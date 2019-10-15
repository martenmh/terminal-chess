//
// Created by root on 10/6/19.
//

#ifndef CHESS_ROOK_H
#define CHESS_ROOK_H

#include "Piece.h"

class Rook : public Piece {
public:
    Rook(int, Color, Type, Player *, Position = {static_cast<HorizontalPosition>(0), 0});

    bool positionPossible(Position) override;
    ~Rook();
};


#endif //CHESS_ROOK_H
