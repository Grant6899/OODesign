/*************************************************************************
	> File Name: Hand.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Thu Aug 16 16:39:37 2018
 ************************************************************************/

#include "Hand.h"

Hand::Hand(){
    minP = 0;
    maxP = 0;
}

void Hand::show(){
    cout << name << ":";
    for(Card& c : handcards)
        cout << c;
}

void Hand::addCard(const Card& c){
    handcards.push_back(c);
    int val = c.getNumber();
    if(val == 1){
        minP += 1;
        maxP += 11;
    }
    else if(val >= 10){
        minP += 10;
        maxP += 10;
    }
    else{
        minP += val;
        maxP += val;
    }
}

bool Hand::isBust(){
    return minP > 21;
}

void Hand::deal(CardDeck& cd){
    Card c = cd.getTopCard();
    addCard(c);
}

bool Hand::willDealerHit(){
    return maxP <= 17;
}

