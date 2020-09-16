//
//  Deck.h
//  Kseri
//
//  Created by George Oikonomou on 10/09/2020.
//

#ifndef Deck_h
#define Deck_h

#include <vector>

#include "Card.hpp"

class Deck {
public:
    Deck();
    Card PickCard();
    bool isEmpty(int sizeNeeded);
    std::vector<Card> PickCards(int number);
    void Shuffle();

private:
    std::vector<Card> cards;
};

#endif /* Deck_h */
