//
// Created by root on 10/6/19.
//

#include <Square.h>
#include <memory>
#include "Board.h"

Board::Board(Enemy *ai, User *usr) : enemy{ai}, user{usr}, flipped{false} {

    // TODO: Set all squares of the board and all pieces on the correct position
    for (unsigned int rank = 1; rank <= 8; ++rank) {

        std::vector<Square *> row;
        for (unsigned int file = 1; file <= 8; ++file) {
            Position pos = {static_cast<HorizontalPosition>(file), rank};
            Square *square;
            // Set user pawns
            if (rank == 2) {
                square = new Square(pos, this, user->getPawn(file - 1));
                // Set ai pawns
            } else if (rank == 7) {
                square = new Square(pos, this, ai->getPawn(file - 1));
                // Set ai back row
            } else if (rank == 8) {
                square = setBackRow(file - 1, pos, ai);
                // Set user back row
            } else if (rank == 1) {
                square = setBackRow(file - 1, pos, user);
            } else {
                square = new Square(pos, this, nullptr);
            }
            row.emplace_back(square);
        }
        squares.push_back(row);
    }

}

Board::Board() = default;

Board::~Board() {
    for (auto row : squares) {
        for (std::vector<Square *>::iterator it = row.begin(); it != row.end(); ++it) {
            delete *it;
            row.erase(it);
        }
    }
}

void Board::flip() {
    flipped = true;
}

Square *Board::setBackRow(unsigned int file, Position &pos, Player *player) {
    Square *square = nullptr;
    // If it is a rook
    if (file == 1 || file == 8) {
        // if the file is the first one of the left (file 1), set index to 0, else index = 1
        square = new Square(pos, this, player->getRook((file == 1) ? 0 : 1));
        // If it is a knight
    } else if (file == 2 || file == 7) {
        square = new Square(pos, this, player->getKnight((file == 2) ? 0 : 1));
        // If it is a bishop
    } else if (file == 3 || file == 6) {
        square = new Square(pos, this, player->getBishop((file == 3) ? 0 : 1));
        // king...
    } else if (file == 4) {
        square = new Square(pos, this, player->getKing());
        // queen.
    } else if (file == 5) {
        square = new Square(pos, this, player->getQueen());
    }
    return square;
}
