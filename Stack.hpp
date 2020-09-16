//
//  Stack.hpp
//  Kseri
//
//  Created by George Oikonomou on 10/09/2020.
//

#ifndef Stack_hpp
#define Stack_hpp

#include <stdio.h>

#include <vector>

#include "Card.hpp"
class Stack {
public:
    Stack();
    Stack(std::vector<Card> initalCards);
    void push(Card c);
    std::vector<Card> cut();
    Card top();
    friend std::ostream& operator<<(std::ostream& os, const Stack& s);
    std::vector<Card> cards;
};
#endif /* Stack_hpp */
