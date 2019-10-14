//
// Created by root on 10/6/19.
//

#include "Square.h"

Square::Square(Position pos, Board *b, Piece *p) : pos{pos}, board{b}, piece{p} {

}

Position Square::getPosition() {
    return pos;
}

Board *Square::getBoard() {
    return this->board;
}

Piece *Square::getPiece() {
    return piece;
}

bool Square::empty() {
    return piece != nullptr;
}

void Square::setEmpty() {
    this->piece = nullptr;
}

void Square::setPiece(Piece *p) {

    this->piece = p;
}
