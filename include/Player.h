//
// Created by root on 10/6/19.
//

#ifndef CHESS_PLAYER_H
#define CHESS_PLAYER_H

#include <string>
#include <vector>

#include "Piece.h"
#include "Rook.h"
#include "Bishop.h"
#include "King.h"
#include "Knight.h"
#include "Pawn.h"
#include "Queen.h"

#include "Color.h"
#include <queue>
#include "Position.h"


class Player {
public:
    explicit Player(Color, std::string);

    void capturePiece(Piece *);

    Pawn *getPawn(int);

    Bishop *getBishop(int);

    Knight *getKnight(int);

    Rook *getRook(int);

    Queen *getQueen();

    King *getKing();
private:
    bool indexOutOfRange(int);
    Color color;
    std::string name;
//    //8:
//    std::vector<std::shared_ptr<Pawn>> pawns;
//    //2:
//    std::vector<std::shared_ptr<Bishop>> bishops;
//    std::vector<std::shared_ptr<Knight>> knights;
//    std::vector<std::shared_ptr<Rook>> rooks;
//
//    //1:
//    std::shared_ptr<Queen> queen;
//    std::shared_ptr<King> king;
//    std::queue<std::shared_ptr<Piece>> capturedPieces;
// Chess notation names
    std::vector<Pawn *> P;
    std::vector<Bishop *> B;
    std::vector<Knight *> N;
    std::vector<Rook *> R;
    Queen *Q;
    King *K;




};


#endif //CHESS_PLAYER_H
