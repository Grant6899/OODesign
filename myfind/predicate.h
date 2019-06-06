/*************************************************************************
	> File Name: predicate.h
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Tue Jun  4 20:47:55 2019
 ************************************************************************/
#ifndef _PREDICATE_H
#define _PREDICATE_H

#include "find.h"

class Predicate{
public:
    virtual bool run(struct dirent* entry) = 0;
    virtual ~Predicate(){}
};

class NamePredicate : public Predicate{
	std::string _name;
public:
	NamePredicate(const std::string& arg);
	bool run(struct dirent* entry);
};

class TypePredicate : public Predicate{
	unsigned long _type;
public:
	TypePredicate(const std::string& arg);
	bool run(struct dirent* entry);
};

#endif
