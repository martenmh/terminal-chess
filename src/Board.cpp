//
// Created by root on 10/6/19.
//

#include <Square.h>
#include <memory>
#include "Board.h"
#include <iostream>

Board::Board(Enemy *ai, User *usr) : enemy{ai}, user{usr}, flipped{false} {

    // TODO: Set all squares of the board and all pieces on the correct position
    for (unsigned int rank = 8; rank >= 1; --rank) {

        std::vector<Square *> row;
        for (unsigned int file = 1; file <= 8; ++file) {
            Position pos = {static_cast<HorizontalPosition>(file), rank};
            std::cout << fileToStr(pos.file) << pos.rank << std::endl;
            Square *square = nullptr;
            // Set user pawns
            if (rank == 2) {
                square = new Square(pos, this, user->getPawn(file - 1));
                // Set ai pawns
            } else if (rank == 7) {

                square = new Square(pos, this, enemy->getPawn(file - 1));
                // Set ai back row
            } else if (rank == 8) {

                square = setBackRow(file, pos, enemy);
                // Set user back row
            } else if (rank == 1) {
                square = setBackRow(file, pos, user);
            } else {
                square = new Square(pos, this, nullptr);
            }

            row.push_back(square);
        }
        squares.push_back(row);
    }

    for (auto row : squares) {
        for (auto file : row) {
            std::cout << fileToStr(file->getPosition().file) << file->getPosition().rank << " ";
        }
        std::cout << "\n";
    }

}

Board::Board() = default;

Board::~Board() {
//    for (auto row : squares) {
//        for (int i = 0; i != row.size(); ++i) {
    // TODO: Delete Square
//        }
//    }
//    squares.clear();
}

#include <algorithm>

void Board::flip() {
    std::reverse(squares.begin(), squares.end());
    flipped = true;
}

Square *Board::setBackRow(unsigned int file, Position &pos, Player *player) {
    // If it is a rook
    if (file == 1 || file == 8) {
        // if the file is the first one of the left (file 1), set index to 0, else index = 1
        return new Square(pos, this, player->getRook((file == 1) ? 0 : 1));
        // If it is a knight
    } else if (file == 2 || file == 7) {
        return new Square(pos, this, player->getKnight((file == 2) ? 0 : 1));
        // If it is a bishop
    } else if (file == 3 || file == 6) {
        return new Square(pos, this, player->getBishop((file == 3) ? 0 : 1));
        // king...
    } else if (file == 4) {
        return new Square(pos, this, player->getKing());
        // queen.
    } else if (file == 5) {
        return new Square(pos, this, player->getQueen());
    }
}

void Board::move(Position from, Position to) {

    Piece *swap;
    Square *prevSquare = this->at(from);
    Square *nextSquare = this->at(to);

    swap = prevSquare->getPiece();
    prevSquare->setEmpty();

    nextSquare->setPiece(swap);
}

Square *Board::at(Position pos) {
    return this->squares.at(pos.rank).at(pos.file);
}



