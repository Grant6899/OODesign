/*************************************************************************
	> File Name: Hand.h
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Thu Aug 16 16:27:27 2018
 ************************************************************************/

#ifndef _HAND_H
#define _HAND_H

#include<vector>
#include "card.h"
#include "carddeck.h"
class Hand{
private:
    vector<Card> handcards;    
    int minP, maxP; 
    string name;
    void addCard(const Card& c);
public:
    Hand();
    void show();
    bool isBust();
    void deal(CardDeck& cd);
};

#endif
