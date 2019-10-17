//
// Created by root on 10/6/19.
//

#ifndef CHESS_PAWN_H
#define CHESS_PAWN_H

#include "Piece.h"

class Pawn : public Piece {
public:
    Pawn(int, Color, Type, Player *, Position = {static_cast<HorizontalPosition>(0), 0});

    std::vector<Square> possiblePositions() override;
    ~Pawn();
};


#endif //CHESS_PAWN_H
