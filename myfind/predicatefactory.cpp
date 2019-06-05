/*************************************************************************
	> File Name: predicatefactory.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Tue Jun  4 22:22:37 2019
 ************************************************************************/

#include "predicatefactory.h"

Predicate* NamePredicateFactory::createPredicate(const std::string& arg){
    return new NamePredicate(arg);
}

Predicate* TypePredicateFactory::createPredicate(const std::string& arg){
    return new TypePredicate(arg);
}

