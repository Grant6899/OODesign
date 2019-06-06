/*************************************************************************
	> File Name: find.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Tue Jun  4 19:40:26 2019
 ************************************************************************/

#include<iostream>
#include<list>
#include<unordered_map>
#include<libgen.h>
#include "predicatefactory.h"

using namespace std;

string USAGE = "this is the usage";

void print_dir_list(list<string>& dirlist){
    for(list<string>::iterator it = dirlist.begin(); it != dirlist.end(); ++it)
        cout << *it << " ";
    cout << endl;
}

bool pred_test(const list<Predicate*>& predicates, struct dirent* entry){
    
    for(list<Predicate*>::const_iterator it = predicates.begin(); it != predicates.end(); ++it)
        if(!(*it)->run(entry)) return false;

    return true;
}

void _traverse(const string& dir, const list<Predicate*>& predicates, int depth, int min_depth, int max_depth){
    //printf("travesing dir: \"%s\"\n", dir.c_str());
    if(depth > max_depth)
        return;

    DIR* dp;
    struct dirent* entry;
    struct stat statbuf;

    if((dp = opendir(dir.c_str())) == NULL){
        fprintf(stderr, "Error: cannot open directory %s\n", dir.c_str());
        return;
    }

    chdir(dir.c_str());
    while((entry = readdir(dp)) != NULL){
        if(strcmp(".", entry->d_name) == 0 || strcmp("..", entry->d_name) == 0) continue;

        //printf("checking dir.c_str(): \"%s\" entry->d_name: \"%s\" \n", dir.c_str(), entry->d_name);
        if(depth >= min_depth && pred_test(predicates, entry))
            printf("%s/%s\n", dir.c_str(), entry->d_name);

        lstat(entry->d_name, &statbuf);

        if(S_ISDIR(statbuf.st_mode)){
            string new_dir = dir + "/" + string(entry->d_name);
            _traverse(new_dir, predicates, depth+1, min_depth, max_depth);
        }
    }

    chdir("..");
    closedir(dp);
}

void traverse(const string& dir, const list<Predicate*>& predicates, int min_depth, int max_depth){
    int depth = 0;
    if(depth > max_depth)
        return;

    struct stat statbuf;
    if(lstat(dir.c_str(), &statbuf)){
        exit(1);
    }
    
    struct dirent* entry = (struct dirent*)malloc(sizeof(struct dirent));
    
    char *dircp1 = new char[dir.size() + 1], *dircp2 = new char[dir.size() + 1];
    strcpy(dircp1, dir.c_str());
    strcpy(dircp2, dir.c_str());

    string dir_name = dirname(dircp1);
    string base_name = basename(dircp2);

    chdir(dir_name.c_str());
    strncpy(entry->d_name, base_name.c_str(), 256);

    if(S_ISREG(statbuf.st_mode))
        entry->d_type = DT_REG;
    else if(S_ISDIR(statbuf.st_mode))
        entry->d_type = DT_DIR;
    else if(S_ISCHR(statbuf.st_mode))
        entry->d_type = DT_CHR;
    else if(S_ISBLK(statbuf.st_mode))
        entry->d_type = DT_BLK;
    else if(S_ISFIFO(statbuf.st_mode))
        entry->d_type = DT_LNK;
    else if(S_ISSOCK(statbuf.st_mode))
        entry->d_type = DT_SOCK;
    else
        entry->d_type = DT_UNKNOWN;

    if(depth >= min_depth && pred_test(predicates, entry))
        printf("%s/%s\n", dir_name.c_str(), base_name.c_str());
    
    if(DT_DIR == entry->d_type){
        //to make it behave exaxtly same as linux find, commented out the line below
        //string new_dir_name = dir_name + "/" + base_name;
        _traverse(dir, predicates, depth+1, min_depth, max_depth);
    }
    
    delete(entry);
    delete [] dircp1;
    delete [] dircp2;
}

void parse_args(int& i, list<Predicate*>& predicates, int& min_depth, int& max_depth, int argc, const char *argv[]){
    
    unordered_map<string, PredicateFactory*> factories;

    factories["-name"] = new NamePredicateFactory();
    factories["-type"] = new TypePredicateFactory();

    while(i < argc){
        if('-' != argv[i][0])
            error_exit(1, USAGE.c_str());
        
        string pred_name = argv[i++];
        
        if(pred_name != "-mindepth" && pred_name != "-maxdepth"){
            string arg = argv[i++];
            predicates.push_back(factories[pred_name]->createPredicate(arg));
        }
        else{
            int depth_val = stoi(string(argv[i++]));
            if(pred_name == "-mindepth") min_depth = depth_val;
            else max_depth = depth_val;
        }
    }

    // clean memory
    for(unordered_map<string, PredicateFactory*>::iterator it = factories.begin(); it != factories.end(); ++it)
        delete(it->second);
}

int main(int argc, const char *argv[]){
    
    list<string> dir_list;

    int i = 1;
    while(i < argc && argv[i][0] != '-')
        dir_list.push_back(argv[i++]);
    
    //print_dir_list(dir_list);
    
    list<Predicate*> predicates;
    
    int min_depth = -1, max_depth = INT_MAX; 
    
    parse_args(i, predicates, min_depth, max_depth, argc, argv);

    for(list<string>::iterator dir_it = dir_list.begin(); dir_it != dir_list.end(); ++dir_it)
        traverse(*dir_it, predicates, min_depth, max_depth);

    return 0;
}
