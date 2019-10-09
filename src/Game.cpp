//
// Created by root on 10/6/19.
//

#include "Game.h"
#include <iostream>

Game::Game() {
    std::string name;
    while (name.empty()) {
        std::cout << "Name: ";
        std::cin >> name;
    }

    char color = '\0';
    while (color != 'b' || color != 'w') {
        std::cout << "Do you wish to play as black or white? (b/w): ";
        std::cin >> color;
    }

    Color col = color == 'b' ? Color::Black : Color::White;
    this->user = User(col, name);
    this->enemy = Enemy(col, "Bot");
    this->board = Board(&enemy, &user);
}


void Game::start() {

}

