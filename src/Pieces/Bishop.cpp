//
// Created by root on 10/6/19.
//

#include "Pieces/Bishop.h"

Bishop::Bishop(int i, Color c, Type t, Player *p, Position pos) : Piece(i, c, t, p, pos) {

}

bool Bishop::positionPossible(Position pos) {


    return false;
}

Bishop::~Bishop() {

}

bool Piece::positionPossible(Position) {

}

