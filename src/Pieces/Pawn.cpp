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
    int amount = this->getColor() == Black ? -1 : 1;
    int leftAmount = this->getColor() == Black ? 1 : -1;

    auto front = position(0, amount);
    auto frontl = position(leftAmount, amount);
    auto frontr = position(leftAmount / -1, amount);

    auto blob = curPos + frontl;
    auto blab = curPos + frontr;

    for (auto b : {blob, blab}) {
        if (!board->positionOutOfBounds(b)) {
            Square *square = board->at(b);
            // If there is a piece and it is an enemy

            if (square->getPiece() && square->getPiece()->getColor() != this->color)
                positions.push_back(square);
        }
    }

    // If the pawn has not yet moved, check if it can move 2 squares
    if (!this->hasMoved()) {
        Position finalPos = finalPositionInPath(this->pos, position(0, amount), 1);
        positions.push_back(board->at(finalPos));
        // Normally use the board->positionsBetween function, but because we already know that the only way is one position to the center use this:
        // If the finalPos is two positions further, otherwise the one in front of the pawn is already in the vector..
        if ((curPos + position(0, amount)).rank < finalPos.rank)
            positions.push_back(board->at(curPos + position(0, amount)));

        // If there is not a piece on the square & the piece is not out of the board
    } else if (board->at(curPos + front)->getPiece() && board->positionOutOfBounds(curPos + front)) {
        positions.push_back(board->at(curPos + front));
    }

    return positions;
}

