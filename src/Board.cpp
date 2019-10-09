//
// Created by root on 10/6/19.
//

#include <Square.h>
#include <memory>
#include "Board.h"

Board::Board(Enemy *ai, User *usr) : enemy{ai}, user{usr} {

    // TODO: Set all squares of the board and all pieces on the correct position
    for (unsigned int rank = 1; rank <= 8; ++rank) {

        // TODO: DELETE THE SQUARES!
        std::vector<Square *> row;
        for (unsigned int file = 1; file <= 8; ++file) {
            Position pos = {static_cast<HorizontalPosition>(file), rank};
            auto *square = new Square(pos, this, ai->getBishop(2));
            row.emplace_back(square);
        }
        squares.push_back(row);
    }

}

Board::Board() = default;

Board::~Board() {
    squares.clear();
}

void Board::flip() {

}
