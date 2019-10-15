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
    for (int i = 0; i < 8; ++i)
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
    return B.at(index);
}

Pawn *Player::getPawn(int index) {
    return P.at(index);
}

Knight *Player::getKnight(int index) {
    return N.at(index);
}

Queen *Player::getQueen() {
    return Q;
}

King *Player::getKing() {
    return K;
}

Rook *Player::getRook(int index) {
    return R.at(index);
}

void Player::capturePiece(Piece *p) {
    unsigned int i = p->getIndex();

    switch (p->getType()) {
        case pawn:
            captureUnknownVector<Pawn *>(&P, i);
            break;
        case rook:
            captureUnknownVector<Rook *>(&R, i);
            break;
        case knight:
            captureUnknownVector<Knight *>(&N, i);

            break;
        case bishop:
            captureUnknownVector<Bishop *>(&B, i);

            break;
        case queen:
            capturedQueue.push(Q);
            break;
        case king:
            capturedQueue.push(K);
            break;
    }
}

template<typename T>
void Player::captureUnknownVector(std::vector<T> *v, int i) {
    T p = v->at(i);
    v->erase(v->begin() + i);
    capturedQueue.push(p);
}

void Player::setBoard(Board *b) {
    this->board = b;
}




