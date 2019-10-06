//
// Created by root on 10/6/19.
//

#include "Player.h"
#include <stdexcept>
#include <utility>

Player::Player(Color c, std::string n) : name{std::move(n)}, color{c} {
    //Create all pieces
}

Bishop *Player::getBishop(int index) {
    if (indexOutOfRange(index))
        return nullptr;

    return bishops[index];
}

Pawn *Player::getPawn(int index) {
    if (indexOutOfRange(index))
        return nullptr;

    return pawns[index];
}

Knight *Player::getKnight(int index) {
    if (indexOutOfRange(index))
        return nullptr;

    return knights[index];
}

Queen *Player::getQueen() {
    return queen;
}

King *Player::getKing() {
    return king;
}

Rook *Player::getRook(int index) {
    if (indexOutOfRange(index))
        return nullptr;

    return rooks[index];
}

bool Player::indexOutOfRange(int index) {
    if (index < 1 || index > 8)
        throw std::out_of_range("Index is out of bounds");
    return false;
}
