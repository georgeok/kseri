//
//  Game.cpp
//  Kseri
//
//  Created by George Oikonomou on 10/09/2020.
//

#include "Game.hpp"

#include <iostream>
#include <sstream>

Game::Game(): stack()
{
    deck.Shuffle();
}

void Game::Start()
{
    stack = Stack(deck.PickCards(4));
    std::cout << "Initial stack" << stack << std::endl;
    while (!deck.isEmpty(12)) {
        Deal();
        Round();
    }
    // give remaining cards to player who last cut
    players[LastPlayerBanked].BankCards(stack.cut());

    for (auto& player : players) {
        std::cout << player.Name << " score: " << player.Score() << " " << player
                  << std::endl
                  << std::endl;
    }
    std::cout << "Stack: " << stack << std::endl;
}

void Game::Deal()
{
    for (auto& player : players) {
        for (int i = 0; i < 6; i++) {
            player.DealCard(deck.PickCard());
        }
        std::cout << "Deal: " << player.Name << " hand: " << player << std::endl;
    }
}

void Game::Round()
{
    for (int i = 0; i < 6; i++) {
        for (auto& player : players) {
            int selection;
            //std::cout << player.Name << ": " << player << std::endl;
            //std::cout << player.Name << ": selct a card from 0-"
            //  << player.noCardsInHand() << std::endl;
            //std::cin >> selection;
            //auto card = player.PlayCard(selection);
            auto card = player.PlayCard();
            //std::cout << player.Name << card << "(" << player << ")"<<
            //std::endl;
            
            // check for kseri
            if(card == stack.top() && stack.cards.size()==1){
                // kseri
                player.addExtraPoints(card.isJack() ? 20 : 10);
            }
            
            if (card == stack.top() || card.isJack()) {
                auto cutStack = stack.cut();
                cutStack.push_back(card);
                player.BankCards(cutStack);
                LastPlayerBanked = player == players[0] ? 0 : 1;
            } else {
                stack.push(card);
            }
            std::cout << "Stack: " << stack << std::endl;
        }
    }
}

std::string Game::printStatus()
{
    std::stringstream ss;
    for (auto player : players) {
        ss << player.Name << " score: " << player.Score() << " " << player
           << std::endl
           << std::endl;
    }
    return ss.str();
}

void Game::End() { }

Stack Game::getStack() {
    return stack;
}
