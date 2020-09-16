//
//  Player.hpp
//  Kseri
//
//  Created by George Oikonomou on 10/09/2020.
//

#ifndef Player_hpp
#define Player_hpp

#include <iostream>
#include <vector>

#include "Card.hpp"
#include "Stack.hpp"

class Player {
public:
    Player(std::string name);
    std::string Name;
    void DealCard(Card c);
    Card PlayCard();
    Card PlayCard(int selection);
    void BankCards(std::vector<Card> toBank);
    int Score();
    int noCardsInHand();
    void addExtraPoints(int points);
    bool operator==(const Player& p);
    friend std::ostream& operator<<(std::ostream& os, const Player& p);

private:
    Stack stack;
    std::vector<Card> hand;
    int extraPoints=0;
};
#endif /* Player_hpp */
