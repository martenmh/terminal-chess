//
// Created by root on 10/6/19.
//

#include "Square.h"

Square::Square(Position pos, Board *b, Piece *p) : pos{pos}, board{b}, piece{p} {

}

Position Square::getPosition() {
    return Position();
}

Board *Square::getBoard() {
    return nullptr;
}

bool Square::setPiece(Piece &) {
    return false;
}

Piece *Square::getPiece() {
    return nullptr;
}
