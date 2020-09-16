#include "Card.hpp"

#include <string>

std::ostream& operator<<(std::ostream& stream, const Suit& suit)
{
    switch (suit) {
    case Suit::clubs:
        stream << "♣️";
        break;
    case Suit::diamonds:
        stream << "♦️";
        break;
    case Suit::hearts:
        stream << "❤️";
        break;
    case Suit::spades:
        stream << "♠️";
        break;
    }
    return stream;
}

Card::Card(Suit _suit, int _rank)
    : suit(_suit)
    , rank(_rank)
{
}

int Card::getRank() { return rank; }

Suit Card::getSuit() { return suit; }

int Card::getPoints() const
{
    if (rank == 1) {
        return 1;
    } else if (rank == 2 && suit == Suit::spades) {
        return 1;
    } else if (rank == 10 && suit == Suit::diamonds) {
        return 2;
    } else if (rank >= 10) {
        return 1;
    } else {
        return 0;
    }
}

bool Card::isJack() { return rank == 11; }

bool Card::operator==(const Card& c) { return rank == c.rank; }

std::string Card::getName() const
{
    switch (rank) {
    case 11:
        return "J";
    case 12:
        return "Q";
    case 13:
        return "K";
    default:
        return std::to_string(rank);
    }
}

std::ostream& operator<<(std::ostream& os, const Card& c)
{
    os << c.suit << c.getName();
    return os;
}
