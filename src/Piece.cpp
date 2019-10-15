//
// Created by root on 10/6/19.
//

#include <Board.h>
#include "Piece.h"

Piece::Piece(int i, Color c, Type t, Player *p, Position pos) : pos{pos}, index{i}, color{c}, pieceType{t}, player{p},
                                                                origPos{pos} {

}

Color Piece::getColor() {
    return color;
}

Type Piece::getType() {
    return pieceType;
}

Position Piece::getPosition() {
    return pos;
}

Player *Piece::getPlayer() {
    return player;
}

int Piece::getIndex() {
    return index;
}

void Piece::setBoard(Board *b) {
    this->board = b;
}

Piece::~Piece() {

}


void Piece::setPosition(Position p) {

    this->board->squares.at(pos.rank).at(pos.file);
    this->pos = p;
}

bool Piece::hasMoved() {
    return origPos.rank == pos.rank && origPos.file == pos.file;
}

