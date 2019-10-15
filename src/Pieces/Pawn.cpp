//
// Created by root on 10/6/19.
//

#include "Pieces/Pawn.h"

Pawn::Pawn(int i, Color c, Type t, Player *p, Position pos) : Piece(i, c, t, p, pos) {

}


Pawn::~Pawn() {

}

#include "Player.h"
#include "Board.h"
#include "Square.h"

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
