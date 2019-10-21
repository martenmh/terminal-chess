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
    // Some functions like:
    // f = flip board/sides?
    // h = help
    // q = quit
    // (=) offer draw

    // parse input:
    // TODO: Apply Rules
    // Rules from https://en.wikipedia.org/wiki/Algebraic_notation_(chess)

    // moving: [Piece name][square to move to], eg.
    // Name of a piece is by an uppercase letter (except pawn, the pawn name is not used in the notation)
    // Be5 (bishop to e5), Nf3, (Knight to f3), f3 (pawn to f3)
    // When capturing an x is inserted immediately before the destination square, eg.
    // Bxe5 (bishop capture piece on e5)
    // or:
    // : is sometimes used instead of x either in the same place or at the end Be5: && B:e5
    // When a pawn makes a capture the file from which the pawn departed is used to identify the pawn: exd5 (pawn on e file to d5)

    // Disambiguating moves
    // disambiguating moves is done by (in presedence order):
    // 1. file of departure,
    // 2. rank of departure,
    // 3. file & rank of departure
    // Although some pieces could also be differentiated by their ranks, the file letter takes precedence.

    // Special moves:
    // En passant captures are indicated by specifying the capturing pawns file of departure, the x destination square and optionally suffix ep. exd6e.p
    // Castling 0-0 kingside castling 0-0-0 queenside castling
    // pawn promotion is [position][piece to promote to] eg. e8Q, promote the pawn on e8 to a queen.

    // Check indicated + or 'ch' appended to the move, double check is 'dbl ch' or ++  appended to the move
    // Checkmate indicated by # or 'mate'  appended to the move
    // eg. Rd8# or Rd8+ etc.

    //End of game
    // 1-0 indicates white won
    // 0-1 indicates black won
    // 1/2-1/2 indicates a draw

    // TODO: Optional implementation of minimal algebraic notation
    // Optionally minimal / abbreviated algebraic notation:
    // Omit indication that a capture has been made, Be5 (instead of Bxe5)
    std::cout << input[0] << input[1] << input[2] << input[3] << std::endl;

    HorizontalPosition b = static_cast<HorizontalPosition>(input[0]);
    HorizontalPosition c = static_cast<HorizontalPosition>(input[2]);

    std::cout << this->getKing()->getColor();
//    Position pos = {.file = a, .rank = static_cast<unsigned int>(input[1] - '0')};
//    Position newPos = {.file = a, .rank = static_cast<unsigned int>(input[3] - '0')};
//
//    if (board->at(pos)->getPiece()->positionPossible(newPos)) {
//        board->move(pos, newPos);
//    } else {
//
//        return false;
//    }

    //TODO if input is invalid return false;

    return true;
}



