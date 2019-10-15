//
// Created by root on 10/6/19.
//
#include <Board.h>
#include "Players/User.h"

User::User(Color c, std::string n) : Player(c, std::move(n)) {

}

#include "Square.h"
#include <iostream>

bool User::set(std::string input) {
    // parse input:


    //TODO if input is invalid return false;
    Position pos = {.file = HorizontalPosition::a, .rank = 1};
    Position paos = {.file = HorizontalPosition::d, .rank = 3};

    Square *s = board->at(pos);
    Piece *p = s->getPiece();
    s->setEmpty();
    Square *newPosition = board->at(paos);

    newPosition->setPiece(p);
    return true;
}



