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
    // Set all squares with pointers to chess pieces on the heap (or nullptr if the square is empty)
    Board(Enemy *, User *);
    Board();
    ~Board();
    // Flip all pieces on the board
    void flip();

    Square *at(Position pos);

    void move(Position from, Position to);
    std::vector<std::vector<Square *>> squares;
private:
    bool flipped;
    // 64 (8 (1 to 8) * 8 (a to h)) Squares

    Enemy *enemy{};
    User *user{};

    Square *setBackRow(unsigned int file, Position &pos, Player *);
};


#endif //CHESS_BOARD_H
