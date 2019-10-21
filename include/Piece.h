//
// Created by root on 10/6/19.
//

#ifndef CHESS_PIECE_H
#define CHESS_PIECE_H


#include "Types.h"
#include "Color.h"
#include "Position.h"

#include <vector>

class Square;
class Board;
class Player;

class Piece {
public:
    Piece(int, Color, Type, Player *, Position = {static_cast<HorizontalPosition>(0), 0});

    void setBoard(Board *);
    ~Piece();
    Color getColor();
    Type getType();
    Position getPosition();
    void setPosition(Position);
    int getIndex();
    Player *getPlayer();

    bool hasMoved();

    // Has to be implemented by derived classes
    /*
     * Returns a vector with all the possible squares for the piece,
     * This can be used to check if the new position given by the player is possible
     * & for the AI algorithm
     */
    virtual std::vector<Square *> possiblePositions() = 0;

    /*
     * This recursive functions checks if it is possible for a piece to move in a certain path without blockades
     * It is useful to know for every piece except the knight,
     * when given an increased pos it wil check in a "straight":
     * horizontal Pos(1, 0) & Pos(-1, 0),
     * vertical Pos(0, 1) &  Pos(0, -1) and
     * diagonal Pos(1, 1) & Pos(1, -1) & Pos(-1, 1) & Pos(-1, -1)
     * path and return the final possible position in the path.
     * The maxPos is for pieces that cannot move more than 2 positions at a time.
     */
    Position finalPositionInPath(Position originalPos, Position increasedPos, int maxPos);

protected:
    Player *player;
    Board *board;
    Position pos;
    Position origPos;
    Color color;
    Type pieceType;
    int index;
};


#endif //CHESS_PIECE_H
