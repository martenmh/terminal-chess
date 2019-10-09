//
// Created by root on 10/6/19.
//

#include "Player.h"
#include <stdexcept>
#include <utility>
#include <memory>

Player::Player(Color c, std::string n) : name{std::move(n)}, color{c} {
    //Create all pieces
    // TODO: DELETE!
    // TODO: maybe set the index 1 higher so each chess piece has the index appropriate for the board
    for (int i = 0; i < 6; ++i)
        P.push_back(new Pawn(i, c, Type::pawn, this));

    for (int i = 0; i < 2; ++i) {
        R.push_back(new Rook(i, c, Type::rook, this));
        N.push_back(new Knight(i, c, Type::knight, this));
        B.push_back(new Bishop(i, c, Type::bishop, this));
    }

    Q = new Queen(c, Type::queen, this);
    K = new King(c, Type::king, this);

}

// TODO: Maybe decrease the index by -1 here so each chess piece has the index appropriate for the board
Bishop *Player::getBishop(int index) {
    if (indexOutOfRange(index))
        return nullptr;

    return B[index];
}

Pawn *Player::getPawn(int index) {
    if (indexOutOfRange(index))
        return nullptr;

    return P[index];

}

Knight *Player::getKnight(int index) {
    if (indexOutOfRange(index))
        return nullptr;

    return N[index];
}

Queen *Player::getQueen() {
    return Q;
}

King *Player::getKing() {
    return K;
}

Rook *Player::getRook(int index) {
    if (indexOutOfRange(index))
        return nullptr;

    return R[index];
}

bool Player::indexOutOfRange(int index) {
    if (index < 1 || index > 8)
        throw std::out_of_range("Index is out of bounds");
    return false;
}

void Player::capturePiece(Piece *) {

}
