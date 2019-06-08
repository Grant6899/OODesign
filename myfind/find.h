/*************************************************************************
	> File Name: find.h
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Tue Jun  4 22:06:33 2019
 ************************************************************************/

#ifndef _FIND_H
#define _FIND_H

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <regex.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fnmatch.h>
#include <dirent.h>
#include <pwd.h>
#include <limits.h>
#include <time.h>

static void error_exit(int exit_code, const std::string& msg){
    fprintf(stderr, "error: %s", msg.empty()? "unknown error, exit" : msg.c_str());
    fputc('\n', stderr);
    exit(exit_code);
}


#endif
