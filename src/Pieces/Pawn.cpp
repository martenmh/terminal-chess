//
// Created by root on 10/6/19.
//

#include "Pieces/Pawn.h"

Pawn::Pawn(int i, Color c, Type t, Player *p, Position pos) : Piece(i, c, t, p, pos) {

}


Pawn::~Pawn() {

}

#include "Board.h"
#include "Square.h"
//#include "Position.h"
std::vector<Square *> Pawn::possiblePositions() {
    std::vector<Square *> positions;

    Position curPos = getPosition();
    auto front = position(0, 1);
    auto front2 = position(0, 2);
    auto frontl = position(-1, 1);
    auto frontr = position(1, 1);

    auto blob = curPos + frontl;
    auto blab = curPos + frontr;

    for (auto b : {blob, blab}) {
        if (!board->positionOutOfBounds(b)) {
            Square *square = board->at(b);
            // If there is a piece and it is an enemy
            if (square->getPiece()->getColor() != this->color)
                positions.push_back(square);
        }
    }

    // If the pawn has not yet moved, check if it can move 2 squares
    if (!this->hasMoved()) {
        positions.push_back(board->at(finalPositionInPath(this->pos, position(0, 1), 2)));

        // If there is not a piece on the square & the piece is not out of the board
    } else if (board->at(curPos + front)->getPiece() && board->positionOutOfBounds(curPos + front)) {
        positions.push_back(board->at(curPos + front));
    }

    return positions;

}

