//
// Created by root on 10/6/19.
//

#ifndef CHESS_PLAYER_H
#define CHESS_PLAYER_H

#include <string>
#include <vector>

class Pawn;

class Bishop;

class Knight;

class Rook;

class Queen;

class King;
//#include "Rook.h"
//#include "Bishop.h"
//#include "King.h"
//#include "Knight.h"
//#include "Pawn.h"
//#include "Queen.h"

#include "Color.h"
#include <queue>

class Piece;

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
    //6:
    std::vector<Pawn *> pawns;
    //2:
    std::vector<Bishop *> bishops;
    std::vector<Knight *> knights;
    std::vector<Rook *> rooks;

    //1:
    Queen *queen;
    King *king;
    std::queue<Piece *> capturedPieces;

};


#endif //CHESS_PLAYER_H
