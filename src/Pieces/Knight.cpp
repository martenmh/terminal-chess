//
// Created by root on 10/6/19.
//

#include "Pieces/Knight.h"

Knight::~Knight() {

}

Knight::Knight(int i, Color c, Type t, Player *p, Position pos) : Piece(i, c, t, p, pos) {

}

bool Knight::positionPossible(Position) {
    return false;
}


