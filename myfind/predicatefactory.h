/*************************************************************************
	> File Name: predicatefactory.h
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Tue Jun  4 22:02:29 2019
 ************************************************************************/

#ifndef _PREDICATEFACTORY_H
#define _PREDICATEFACTORY_H

#include "predicate.h"

class PredicateFactory{
public:
    virtual Predicate* createPredicate(const std::string& arg) = 0;
    virtual ~PredicateFactory(){}
};

class NamePredicateFactory : public PredicateFactory{
public:
    NamePredicateFactory(){}
    virtual Predicate* createPredicate(const std::string& arg);
    virtual ~NamePredicateFactory(){};
};

class TypePredicateFactory : public PredicateFactory{
public:
    TypePredicateFactory(){}
    virtual Predicate* createPredicate(const std::string& arg);
    virtual ~TypePredicateFactory(){};
};


#endif
