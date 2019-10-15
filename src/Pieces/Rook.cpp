//
// Created by root on 10/6/19.
//

#include "Pieces/Rook.h"

Rook::Rook(int i, Color c, Type t, Player *p, Position pos) : Piece(i, c, t, p, pos) {
}


Rook::~Rook() {

}

bool Rook::positionPossible(Position) {
    return false;
}
