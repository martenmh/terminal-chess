//
// Created by root on 10/6/19.
//

#ifndef CHESS_SQUARE_H
#define CHESS_SQUARE_H

#include "Piece.h"
#include "Board.h"

#include "Position.h"

class Square {
public:
    Square(Position, Board *, Piece * = nullptr);

    Position getPosition();

    Board *getBoard();

    bool setPiece(Piece *);

    Piece *getPiece();

    bool empty();

    // Remove piece
    void setEmpty();
private:
    Piece *piece;
    Board *board;
    Position pos;
};


#endif //CHESS_SQUARE_H
