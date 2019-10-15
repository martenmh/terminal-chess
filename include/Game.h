//
// Created by root on 10/6/19.
//

#ifndef CHESS_GAME_H
#define CHESS_GAME_H

#include "Enemy.h"
#include "User.h"
#include "Board.h"

class Game {
public:
    Game();
    void start();
    void pause();
    void stop();

    void next();
    void prev();

    static void displayPlayer(Player *);


private:
    Board board;
    Enemy enemy;
    User user;
};


#endif //CHESS_GAME_H
