//
// Created by root on 10/6/19.
//

#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

#include <vector>
#include <memory>
#include "User.h"
#include "Enemy.h"

class User;

class Enemy;

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

    bool positionOutOfBounds(int rank, int file);

    bool positionOutOfBounds(Position pos);

    void move(Position from, Position to);
    std::vector<std::vector<Square *>> squares;

    /*
     * Returns all positions between 2 positions that are either diagonally or straight away from each other
     */
    std::vector<Position> positionsBetween(Position fp, Position lp);

    void display();
private:
    bool flipped;
    // 64 (8 (1 to 8) * 8 (a to h)) Squares

    Enemy *enemy{};
    User *user{};

    Square *setBackRow(Position &pos, Player *);
};


#endif //CHESS_BOARD_H
