//
// Created by root on 10/6/19.
//

#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

#include <vector>
#include <memory>
#include "User.h"
#include "Enemy.h"

class Square;

#include "Position.h"

class Board {
public:
    Board(Enemy *, User *);

    Board();

    ~Board();

    // Flip all pieces on the board
    void flip();
private:
    // 64 (8 (1 to 8) * 8 (a to h)) Squares
    std::vector<std::vector<Square *>> squares;
    Enemy *enemy{};
    User *user{};
};


#endif //CHESS_BOARD_H
