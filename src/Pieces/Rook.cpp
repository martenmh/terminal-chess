//
// Created by root on 10/6/19.
//

#include "Pieces/Rook.h"

Rook::Rook(int i, Color c, Type t, Player *p, Position pos) : Piece(i, c, t, p, pos) {
}


Rook::~Rook() {

}

std::vector<Square> Rook::possiblePositions() {
    return std::vector<Square>();
}
