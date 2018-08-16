/*************************************************************************
	> File Name: CardDeck.h
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Wed Aug 15 17:44:19 2018
 ************************************************************************/

#ifndef _CARDDECK_H
#define _CARDDECK_H

#include "card.h"
#include<vector>

class CardDeck{
private:
    std::vector<Card> deck_;

public:
    CardDeck(int n);
    void shuffle();
    Card getTopCard();
};

#endif
