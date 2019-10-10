//
// Created by root on 10/6/19.
//

#include "Game.h"
#include <iostream>
#include <Square.h>

Game::Game() {
    std::string name;
    while (name.empty()) {
        std::cout << "Name: ";
        std::cin >> name;
    }

    char color = 'b';
//    std::cout << "Do you wish to play as black or white? (b/w): ";
//    std::cin >> color;

    Color col = color == 'b' ? Color::Black : Color::White;
    this->user = User(col, name);
    this->enemy = Enemy(col, "Bot");
    this->board = Board(&enemy, &user);
//    for(auto row : board.squares){
//        for(Square *column : row){
//            std::cout << column->piece->getType() << std::endl;
//        }
//    }
    std::cout << "Whaa" << std::endl;
}


void Game::start() {

}

