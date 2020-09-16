//
//  Card.h
//  Kseri
//
//  Created by George Oikonomou on 10/09/2020.
//

#ifndef Card_hpp
#define Card_hpp
#include <iostream>
enum class Suit { spades,
    hearts,
    diamonds,
    clubs };

class Card {
public:
    Card(Suit suit, int rank);
    int getRank();
    Suit getSuit();
    std::string getName() const;
    int getPoints() const;
    bool isJack();
    friend std::ostream& operator<<(std::ostream& os, const Card& c);
    bool operator==(const Card& c);

private:
    int rank;
    Suit suit;
    int points;
};

#endif /* Card_h */
