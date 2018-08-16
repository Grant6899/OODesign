/*************************************************************************
	> File Name: Card.h
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Wed Aug 15 16:36:36 2018
 ************************************************************************/

#ifndef _CARD_H
#define _CARD_H

#include <iostream>

//provide readability for the suits, without having ot use strings.
enum suits {JOKER, HEART, SPADE, CLUB, DIAMOND};

//This will represent a card in a deck
class Card {
private:
	int suit_;			//suit of the card
	int number_;			//the number of the card
public:
	Card();				//default constructor
	Card(int suit, int num);		
	int getSuit() const;		//accessors
	int getNumber() const;
	void setSuit(int newSuit);	//mutators
	void setNumber(int newNum);
	friend std::ostream& operator<<(std::ostream&, Card&);
};

#endif
