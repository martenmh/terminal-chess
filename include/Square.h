//
// Created by root on 10/6/19.
//

#ifndef CHESS_SQUARE_H
#define CHESS_SQUARE_H

#include "Piece.h"
#include "Board.h"


class Square {
public:
    Piece* piece;
private:
    Board& board;
    Position pos;
};


#endif //CHESS_SQUARE_H
