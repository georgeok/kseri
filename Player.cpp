//
//  Player.cpp
//  Kseri
//
//  Created by George Oikonomou on 10/09/2020.
//

#include "Player.hpp"

std::ostream& operator<<(std::ostream& os, const Player& p)
{
    if (p.hand.size() > 0) {
        os << "Hand: ";
        for (auto card : p.hand) {
            os << card << " ";
        }
    }

    if (p.stack.cards.size() > 0) {
        os << "Bank: ";
        for (auto card : p.stack.cards) {
            os << card << " ";
        }
    }
    return os;
}

Card Player::PlayCard(int selection)
{
    auto c = hand.at(selection);
    hand.erase(hand.begin() + selection);
    return c;
}

Card Player::PlayCard()
{
    auto c = hand.back();
    hand.pop_back();
    return c;
}

void Player::DealCard(Card c) { hand.push_back(c); }

void Player::BankCards(std::vector<Card> toBank)
{
    stack.cards.insert(stack.cards.end(), toBank.begin(), toBank.end());
}
int Player::noCardsInHand() { return hand.size(); }

int Player::Score()
{
    int score = 0;
    for (auto c : stack.cards) {
        score += c.getPoints();
    }
    if (stack.cards.size() > 26){
        score += 3;
    }
    score += extraPoints;
    return score;
}

bool Player::operator==(const Player& p) { return Name == p.Name; }

Player::Player(std::string name)
    : Name(name)
    , stack()
{
}

void Player::addExtraPoints(int points) { 
    extraPoints += points;
}

