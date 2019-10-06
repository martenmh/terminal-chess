//
// Created by root on 10/6/19.
//

#ifndef CHESS_PIECE_H
#define CHESS_PIECE_H

#include "Player.h"

enum Type{
    Pawn,
    Rook,
    Knight,
    Bishop,
    Queen,
    King
};

class Piece {
public:
    Piece(Color, Type);
    Color getColor();
    Type getType();
protected:
    Color color;
    Type pieceType;
};


#endif //CHESS_PIECE_H
