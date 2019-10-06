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

    char color;
    while (color != 'b' || color != 'w') {
        std::cout << "Do you wish to play as black or white? (b/w): ";
        std::cin >> color;
    }
    Color col = color == 'b' ? Color::Black : Color::White;
    user = User(col, name);
    enemy = Enemy(col, "Bot");
    board = Board(&enemy, &user);
}


void Game::start() {

}

