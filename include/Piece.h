//
// Created by root on 10/6/19.
//

#ifndef CHESS_PIECE_H
#define CHESS_PIECE_H


#include "Types.h"
#include "Color.h"
#include "Position.h"

class Player;

class Piece {
public:
    Piece(int, Color, Type, Player *, Position = {static_cast<HorizontalPosition>(0), 0});

    ~Piece();
    Color getColor();
    Type getType();

    Position getPosition();

    int getIndex();

    Player *getPlayer();
protected:
    Player *player;
    Position pos;
    Color color;
    Type pieceType;
    int index;
};


#endif //CHESS_PIECE_H
