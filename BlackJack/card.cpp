/*************************************************************************
	> File Name: Card.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Wed Aug 15 16:50:14 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<string>
#include "Card.h"

using namespace std;

Card::Card(){
    suit_ = 0;
    number_ = 0;
}

Card::Card(int suit, int num) : suit_(suit), number_(num){

}

int Card::getSuit() const{
    return this->suit_;
}

int Card::getNumber() const{
    return this->number_;    
}

void Card::setSuit(int newSuit){
    this->suit_ = newSuit;
}

void Card::setNumber(int newNum){
    this->number_ = newNum;
}

string getNumDisplay(const Card& c){
    string pic[13] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};    
    return pic[c.getNumber()];
}

string getSuitDisplay(const Card& c){
    switch(c.getSuit()){
        case 0 : return "Joker";
        case 1 : return "Heart";
        case 2 : return "Spade";
        case 3 : return "Club";
        case 4 : return "Diamond";
    }
}


std::ostream& operator<<(std::ostream& os, Card& c){
    os << getSuitDisplay(c) << " " << getNumDisplay(c);
    return os;
}
