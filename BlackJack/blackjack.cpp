/*************************************************************************
	> File Name: blackjack.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon Aug 13 14:16:21 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class CardDeck{
private:
    vector<int> card_deck;
    int remaining;

public:
    CardDeck() : remaining(54){
        card_deck = vector<int>(52, 0);
    }

    void shuffle(){
        for(int i = remaining; i >= 0; --i){
            int idx = rand() % i;
            swap(card_deck[idx], card_deck[i]);
        }
    }

    int getCard(){
        int idx = rand() % remaining;
        swap(card_deck[idx], card_deck[remaining - 1]);
        return(card_deck[(remaining--) - 1]);
    }

    void show_deck(){
        for(int i = remaining-1; i >= 0; --i)
            cout << card_deck[i] << " ";
        cout << endl;
    }
}

class Player{
private:
    vector<int> cards;
    int point;
    bool isDealer;
public:

    Player(bool isDealer){
        point = 0;
    }

    string cardtodes(int card){
        int suit = card / 13;
        int num = card % 13;
        vector<string> ch{"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"}; 
        string res = ""; 
        switch(suit){
            case 0 : res += "Spade ";
            case 1 : res += "Heart ";
            case 2 : res += "Club ";
            case 3 : res += "Diamond ";
        }
        
        res += ch[num];
        return res;
    }

    void hit(int card){
        cards.push_back(card);
        point += card % 13;
        cout << "getting " << cardtodes(card) << endl;
    }

    void show(bool isDealer){
        if(isDealer){
            for(int i = 1; i < cards.size(); ++i)
                cout << cards[i] << " ";
            cout << endl;

        }
        else{
            for(int i = 0; i < cards.size(); ++i)
                cout << cards[i] << " ";
            cout << endl;
        }
    }
};

void start(){
    CardDeck cd;
    cd.shuffle();
    
    Player dealer, me;

    dealer.hit(cd.getCard());
    me.hit(cd.getCard());
    dealer.hit(cd.getCard());
    
    cout << "Dealer: \n";
    dealer.show(true);
    cout << endl;
    

    string command;
    cin << command;
    while(command != "exit" || command != "e"){

    }

}

int main(){
    while(true){
        cout << ""
    }
}
