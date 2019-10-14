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
        for (auto file : row) {
//            std::cout << fileToStr(file->getPosition().file) << file->getPosition().rank << " ";
            if (file->getPiece()) {
                char color = file->getPiece()->getColor() == Color::White ? 'W' : 'B';
                std::cout << color << (char) file->getPiece()->getType() << " ";
            } else {
                std::cout << ' ' << " ";
            }
        }
        std::cout << "\n";
    }
    std::cout << '\n';
    board.flip();
    for (auto row : board.squares) {

        for (auto file : row) {
//            std::cout << fileToStr(file->getPosition().file) << file->getPosition().rank << " ";
            if (file->getPiece()) {
                char color = file->getPiece()->getColor() == Color::White ? 'W' : 'B';
                std::cout << color << (char) file->getPiece()->getType() << " ";

            } else {
                std::cout << ' ' << " ";
            }
        }
        std::cout << "\n";
    }
}


void Game::start() {

}
