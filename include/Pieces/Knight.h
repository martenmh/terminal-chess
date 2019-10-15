//
// Created by root on 10/6/19.
//

#ifndef CHESS_KNIGHT_H
#define CHESS_KNIGHT_H

#include "Piece.h"

class Knight : public Piece {
public:
    Knight(int, Color, Type, Player *, Position = {static_cast<HorizontalPosition>(0), 0});

    bool positionPossible(Position) override;
    ~Knight();
};


#endif //CHESS_KNIGHT_H
