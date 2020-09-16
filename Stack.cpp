//
//  Stack.cpp
//  Kseri
//
//  Created by George Oikonomou on 10/09/2020.
//

#include "Stack.hpp"

Stack::Stack(std::vector<Card> initalCards)
{
    cards.insert(cards.end(), initalCards.begin(), initalCards.end());
}

void Stack::push(Card c) { cards.push_back(c); }

Card Stack::top() { return cards.back(); }

std::vector<Card> Stack::cut()
{
    auto cutCards = cards;
    cards.clear();
    return cutCards;
}

std::ostream& operator<<(std::ostream& os, const Stack& s)
{
    for (auto card : s.cards) {
        os << card << " ";
    }
    return os;
}

Stack::Stack() {

}
