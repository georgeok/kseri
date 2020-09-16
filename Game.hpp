//
//  Game.hpp
//  Kseri
//
//  Created by George Oikonomou on 10/09/2020.
//

#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>

#include <vector>

#include "Deck.hpp"
#include "Player.hpp"
#include "Stack.hpp"

class Game {
public:
    Game();
    void End();
    void Start();
    std::string printStatus();
    Stack getStack();

private:
    void Deal();
    void Round();
    Deck deck;
    Stack stack;
    Player players[2] { Player("P1"), Player("P2") };
    int LastPlayerBanked = 0;
};

#endif /* Game_hpp */
