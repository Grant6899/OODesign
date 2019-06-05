/*************************************************************************
	> File Name: predicate.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Tue Jun  4 21:50:05 2019
 ************************************************************************/

#include "predicate.h"

NamePredicate::NamePredicate(const std::string& arg){
    _name = arg;
}

bool NamePredicate::operator()(struct dirent* entry){
    return strcmp(entry->d_name, _name.c_str()) == 0;
}

TypePredicate::TypePredicate(const std::string& arg){
    switch(arg[0]){
        case 'b' : _type = DT_BLK; break;
        case 'c' : _type = DT_CHR; break;
        case 'd' : _type = DT_DIR; break;
        case 'p' : _type = DT_FIFO; break;
        case 'f' : _type = DT_REG; break;
        case 'l' : _type = DT_LNK; break;
        case 's' : _type = DT_SOCK; break;
        default: error_exit(2, "invalid type");
    }
}

bool TypePredicate::operator()(struct dirent* entry){
    return entry->d_type == _type;
}