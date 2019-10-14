//
// Created by root on 10/6/19.
//

#include "Game.h"
#include <iostream>
#include <Square.h>


Game::Game() {
//    std::string name;
//    while (name.empty()) {
//        std::cout << "Name: ";
//        std::cin >> name;
//    }
//
//    char color = 'b';
////    std::cout << "Do you wish to play as black or white? (b/w): ";
////    std::cin >> color;
//
//    Color col = color == 'b' ? Color::Black : Color::White;
    this->user = User();
    this->enemy = Enemy();

    this->board = Board(&enemy, &user);
    std::cout << user.getQueen()->getType() << std::endl;
    std::cout << user.getQueen()->getColor() << std::endl;
    Type types;

    for (auto row : board.squares) {
        for (Square *column : row) {

            std::cout << typeEnumToStr(column->getPiece()->getType()) << std::endl;
            std::cout << column->getPiece() << std::endl;
            std::cout << column->getPosition().rank << column->getPosition().file << std::endl;
            std::cout << column->getPiece()->getPosition().file << column->getPiece()->getPosition().rank << std::endl;
        }
    }
    std::cout << "Whaa" << std::endl;
}


void Game::start() {

}
