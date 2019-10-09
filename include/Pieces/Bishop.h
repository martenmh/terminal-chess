//
// Created by root on 10/6/19.
//

#ifndef CHESS_BISHOP_H
#define CHESS_BISHOP_H
#include "Piece.h"

class Bishop : public Piece {
public:
    Bishop(int, Color, Type, Player *, Position = {static_cast<HorizontalPosition>(0), 0});

    ~Bishop();
};


#endif //CHESS_BISHOP_H
