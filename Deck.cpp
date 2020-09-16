//
//  Deck.cpp
//  Kseri
//
//  Created by George Oikonomou on 10/09/2020.
//

#include "Deck.hpp"

#include <algorithm>
#include <random>

#include "Card.hpp"

Deck::Deck()
{
    for (auto suit : { Suit::spades, Suit::diamonds, Suit::hearts, Suit::clubs }) {
        for (int rank = 1; rank <= 13; rank++) {
            auto card = Card(static_cast<Suit>(suit), rank);
            cards.emplace_back(card);
        }
    }
}

bool Deck::isEmpty(int sizeNeeded) { return int(cards.size()) < sizeNeeded; }

std::vector<Card> Deck::PickCards(int number)
{
    std::vector<Card> cards;
    for (int i = 0; i < number; i++) {
        cards.push_back(PickCard());
    }
    return cards;
}

Card Deck::PickCard()
{
    auto c = cards.back();
    cards.pop_back();
    return c;
}

void Deck::Shuffle()
{
    std::random_device mch;
    std::shuffle(std::begin(cards), std::end(cards), mch);
}
