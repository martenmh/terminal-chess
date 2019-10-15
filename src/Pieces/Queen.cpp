//
// Created by root on 10/6/19.
//

#include "Pieces/Queen.h"

Queen::~Queen() {

}

Queen::Queen(Color c, Type t, Player *p, Position pos) : Piece(0, c, t, p, pos) {

}

bool Queen::positionPossible(Position) {
    return false;
}
