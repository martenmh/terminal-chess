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

//    this->board->squares.at(pos.rank).at(pos.file);
    this->pos = p;
}

bool Piece::hasMoved() {
    return origPos.rank == pos.rank && origPos.file == pos.file;
}

#include "Square.h"

Position Piece::finalPositionInPath(Position originalPos, Position increasedPos, int maxPos) {
    Position newPos = originalPos + increasedPos;

    // If the function has reached the max position
    if (maxPos == 0)
        return originalPos;

    // If the new position is not on the board
    if (board->positionOutOfBounds(newPos.file, newPos.rank))
        return originalPos;

    // If the piece on a square in the path is an enemy, return it's position
    if (board->at(newPos)->getPiece() &&
        board->at(newPos)->getPiece()->getColor() != board->at(originalPos)->getPiece()->getColor())
        return newPos;

    // If the new position contains a piece return pos
    if (board->at(newPos)->getPiece())
        return originalPos;

    return finalPositionInPath(newPos, increasedPos, maxPos - 1);
}



