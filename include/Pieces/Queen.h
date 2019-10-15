//
// Created by root on 10/6/19.
//

#ifndef CHESS_QUEEN_H
#define CHESS_QUEEN_H

#include "Piece.h"

class Queen : public Piece {
public:
    Queen(Color, Type, Player *, Position = {static_cast<HorizontalPosition>(0), 0});

    bool positionPossible(Position) override;
    ~Queen();
};


#endif //CHESS_QUEEN_H
