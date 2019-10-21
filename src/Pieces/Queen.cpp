//
// Created by root on 10/6/19.
//

#include "Pieces/Queen.h"

Queen::~Queen() {

}

Queen::Queen(Color c, Type t, Player *p, Position pos) : Piece(0, c, t, p, pos) {

}

std::vector<Square *> Queen::possiblePositions() {
    std::vector<Square *> positions;
    return positions;
}

