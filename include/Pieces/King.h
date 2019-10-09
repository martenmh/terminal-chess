//
// Created by root on 10/6/19.
//

#ifndef CHESS_KING_H
#define CHESS_KING_H

#include "Piece.h"

class King :public Piece {
public:
    King(Color, Type, Player *, Position = {static_cast<HorizontalPosition>(0), 0});

    ~King();
};


#endif //CHESS_KING_H
