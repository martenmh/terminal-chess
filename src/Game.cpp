//
// Created by root on 10/6/19.
//

#include "Game.h"
#include <iostream>
#include <Square.h>


Game::Game() {

    char color = '\0';
    do {
        std::cout << "Do you wish to play as black or white? (b/w): ";
        std::cin >> color;
    } while (color == '\0');

    Color col = color == 'b' ? Color::Black : Color::White, botCol = color == 'b' ? Color::White : Color::Black;
    this->user = User(col, "player");
    this->enemy = Enemy(botCol, "bot");
    this->board = Board(&enemy, &user);
    user.setBoard(&board);
    enemy.setBoard(&board);

    start();
}

#include "Player.h"

void Game::start() {

//    ANSI color codes:
//    foreground background
//    black        30         40
//    red          31         41
//    green        32         42
//    yellow       33         43
//    blue         34         44
//    magenta      35         45
//    cyan         36         46
//    white        37         47
//
//    Additionally, you can use these:
//
//    reset             0  (everything back to normal)
//    bold/bright       1  (often a brighter shade of the same colour)
//    underline         4
//    inverse           7  (swap foreground and background colours)
//    bold/bright off  21
//    underline off    24



    bool b = true;

    // Main program loop:
    do {
        // Clear screen:
        std::cout << "\033[2J\033[1;1H";

        // Display board
        board.display();

        for (auto t : user.getPawn(3)->possiblePositions()) {
            std::cout << fileToStr(t->getPosition().file) << t->getPosition().rank << std::endl;
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

void Game::displayPlayer(Player *p) {
    std::cout << p->getName() << ": ";
    for (auto piece : p->getCapturedQueue()) {
        std::cout << (char) piece->getType() << " ";
    }
    std::cout << "\n";
}
