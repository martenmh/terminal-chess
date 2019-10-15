//
// Created by root on 10/6/19.
//

#ifndef CHESS_PIECE_H
#define CHESS_PIECE_H


#include "Types.h"
#include "Color.h"
#include "Position.h"

class Board;
class Player;

class Piece {
public:
    Piece(int, Color, Type, Player *, Position = {static_cast<HorizontalPosition>(0), 0});

    void setBoard(Board *);
    ~Piece();
    Color getColor();
    Type getType();
    Position getPosition();
    void setPosition(Position);
    int getIndex();
    Player *getPlayer();

    bool hasMoved();

    // Has to be implemented by derived classes
    virtual bool positionPossible(Position);

protected:
    Player *player;
    Board *board;
    Position pos;
    Position origPos;
    Color color;
    Type pieceType;
    int index;
};


#endif //CHESS_PIECE_H
