//
// Created by root on 10/6/19.
//

#include "Pieces/Bishop.h"

Bishop::Bishop(int i, Color c, Type t, Player *p, Position pos) : Piece(i, c, t, p, pos) {

}

Bishop::~Bishop() {

}

std::vector<Square *> Bishop::possiblePositions() {
    std::vector<Square *> positions;
    return positions;
}


