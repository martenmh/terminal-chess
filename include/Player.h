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

class Board;

class Player {
public:
    explicit Player(Color, std::string);

    void setBoard(Board *);
    void capturePiece(Piece *);

    /*
     * Get the pieces of the player:
     */
    Pawn *getPawn(int);
    Bishop *getBishop(int);
    Knight *getKnight(int);
    Rook *getRook(int);
    Queen *getQueen();
    King *getKing();

    /*
     * Get other information of the player
     */
    Color getColor();

    std::string getName();

    std::vector<Piece *> getCapturedQueue();

protected:

    template<typename T>
    void captureUnknownVector(std::vector<T> *, int);

    Color color;
    std::string name;

    /*
     * Chess notation names:
     * Pawn(P) contains 8 pawns;
     * Bishop(B), Knight(N) & Rook(R) contain 2.
     */
    std::vector<Pawn *> P;
    std::vector<Bishop *> B;
    std::vector<Knight *> N;
    std::vector<Rook *> R;
    Queen *Q;
    King *K;

    std::vector<Piece *> capturedQueue;

    Board *board;

};


#endif //CHESS_PLAYER_H
