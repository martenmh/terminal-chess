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

//
    char color = '\0';
    do {
        std::cout << "Do you wish to play as black or white? (b/w): ";
        std::cin >> color;
    } while (color == '\0');


    Color col = color == 'b' ? Color::Black : Color::White, botCol = color == 'b' ? Color::White : Color::Black;
    this->user = User(col, name);
    this->enemy = Enemy(botCol, "bot");
    this->board = Board(&enemy, &user);
    user.setBoard(&board);
    enemy.setBoard(&board);

    start();
}


void Game::start() {
    bool b = true;

    // Main program loop:
    do {
        std::cout << "    a  b  c  d  e  f  g  h" << '\n' << "  -------------------------";
        std::cout << '\n';
        for (auto row : board.squares) {
            std::cout << row.at(0)->getPosition().rank << " |";
            for (auto file : row) {

                if (file->getPiece()) {
                    char color = file->getPiece()->getColor() == Color::White ? 'W' : 'B';
                    std::cout << color << (char) file->getPiece()->getType() << "|";
                } else {
                    std::cout << "  |";
                }
            }
            std::cout << "\n" << "  |--|--|--|--|--|--|--|--|" << '\n';
        }

        std::string input;

        // Wait for input
        while (input.empty()) {
            std::cout << ": ";
            std::cin >> input;
        }
        user.set(input);
        enemy.play();

    } while (b);

}
