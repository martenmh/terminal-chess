//
// Created by root on 10/6/19.
//

#include "Piece.h"

Piece::Piece(int i, Color c, Type t, Player *p, Position pos) : pos{pos}, index{i}, color{c}, pieceType{t}, player{p} {

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
