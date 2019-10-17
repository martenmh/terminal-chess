//
// Created by root on 10/6/19.
//

#include "Pieces/Pawn.h"

Pawn::Pawn(int i, Color c, Type t, Player *p, Position pos) : Piece(i, c, t, p, pos) {

}


Pawn::~Pawn() {

}

//#include "Position.h"
std::vector<Square> Pawn::possiblePositions() {
    std::vector<Square *> positions;

    // Check front left, front right
    Position curPos = getPosition();
    Position frontL = position(0, 1);
    Position frontL = position(0, 2);
    Position frontL = position(1, 1);
    Position frontL = position(-1, 1);


    for (auto b : {curPos + position(2, 1), position(5, 2)}) {
        Square *square = board->at(b);
        if (square->getPiece()->getColor() != this->color)
            positions.push_back(square);
    }

    if (this->hasMoved()) {
        finalPositioInPath(this->pos, position(0, 1), 2);
    }


}

bool Pawn::positionPossible(Position p) {
    bool isWhite = player->getColor() == Color::White;
    const bool posIsFree = !board->at(p)->getPiece();
    const bool posContainsEnemy = board->at(p)->getPiece()->getColor() != player->getColor();
    const bool moveForwardPossible = p.file == pos.file && posIsFree;
    const bool capturePossible = (p.file == pos.file + 1 || p.file == pos.file - 1) && posContainsEnemy;
    // If the pawn has moved
    if (this->hasMoved()) {
        // If the new position is only 1 row different (forwards ie. down for black and up for white)
        if ((isWhite && p.rank == pos.rank + 1) || (!isWhite && p.rank == pos.rank - 1)) {
            // If the new position is on the same file && there is no piece
            if (moveForwardPossible) return true;
            // If the pawn can capture
            if (capturePossible) return true;
        }
        // If the pawn hasn't moved
    } else {
        // If the new position is only 1 row different (forwards ie. down for black and up for white)
        if ((isWhite && p.rank == pos.rank + 1) || (!isWhite && p.rank == pos.rank - 1)) {
            // If the new position is on the same file && there is no piece
            if (moveForwardPossible) return true;
            // If the pawn can capture
            if (capturePossible) return true;
        }

        if ((isWhite && p.rank == pos.rank + 2) || (!isWhite && p.rank == pos.rank - 2)) {
            // If the new position is on the same file && there is no piece
            if (moveForwardPossible) return true;
        }
    }

    return false;
}
