//
// Created by root on 10/6/19.
//

#ifndef CHESS_SQUARE_H
#define CHESS_SQUARE_H

#include "Piece.h"
#include "Board.h"

#include "Position.h"

class Board;

class Square {
public:
    Square(Position, Board *, Piece * = nullptr);

    /*
     * Self explanatory
     */
    Position getPosition();
    Board *getBoard();

    Color getColor();
    void setPiece(Piece *);
    Piece *getPiece();


    /*
     * Set the chess piece on the square empty
     * sets the piece as a nullptr because it doesn't point to a piece..
     */
    void setEmpty();

    /*
     * Checks if there is a piece on the square
     */
    bool empty();
private:
    Color color;
    Piece *piece;
    Board *board;
    Position pos;
};


#endif //CHESS_SQUARE_H
