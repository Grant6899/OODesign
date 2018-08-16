/*************************************************************************
	> File Name: CardDeck.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Wed Aug 15 17:50:14 2018
 ************************************************************************/

#include "carddeck.h"
#include<vector>

CardDeck::CardDeck(int n){
    deck_ = std::vector<Card>(52 * n);
    for(int i = 0; i < n; ++i)
        for(int suit = 1; suit <= 4; ++suit)
            for(int num = 0; num < 13; ++num)
                deck_[i * 52 + (suit - 1) * 13 + num] = Card(suit, num);
}

void CardDeck::shuffle(){
    for(int i = deck_.size() - 1; i >= 0; i--){
        int idx = rand() % i;
        std::swap(deck_[idx], deck_[i]);
    }
}

Card CardDeck::getTopCard(){
    Card res = deck_.back();
    deck_.pop_back();
    return res;
}

