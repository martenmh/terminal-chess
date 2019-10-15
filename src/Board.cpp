//
// Created by root on 10/6/19.
//

#include <Square.h>
#include <memory>
#include "Board.h"
#include <iostream>

Board::Board(Enemy *ai, User *usr) : enemy{ai}, user{usr}, flipped{false} {

    // TODO: Set all squares of the board and all pieces on the correct position
    for (unsigned int rank = 1; rank <= 8; ++rank) {

        std::vector<Square *> row;
        for (unsigned int file = 1; file <= 8; ++file) {
            Position pos = {static_cast<HorizontalPosition>(file), rank};

            Square *square = nullptr;
            // Set user pawns
            if (rank == 2) {
                square = new Square(pos, this, user->getPawn(file - 1));
                // Set ai pawns
            } else if (rank == 7) {

                square = new Square(pos, this, enemy->getPawn(file - 1));
                // Set ai back row
            } else if (rank == 8) {

                square = setBackRow(pos, enemy);
                // Set user back row
            } else if (rank == 1) {
                square = setBackRow(pos, user);
            } else {
                square = new Square(pos, this, nullptr);
            }

            row.push_back(square);
        }
        squares.push_back(row);
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

Square *Board::setBackRow(Position &pos, Player *player) {
    // If it is a rook
    unsigned int file = pos.file;
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

void Board::display() {
    std::cout << "    a  b  c  d  e  f  g  h\n  -------------------------\n";
    // Reverse loop so the board starts at 8
    for (int i = 7; i >= 0; --i) {
        auto row = this->squares.at(i);
        std::cout << row.at(0)->getPosition().rank << " |";
        for (auto file : row) {
            if (file->getPiece()) {
                char color = file->getPiece()->getColor() == Color::White ? 'W' : 'B';
                std::cout << color << (char) file->getPiece()->getType() << "|";

                // TODO (maybe?): set foreground and background colors depending on the colors
                // TODO create Color class
                //// "\033[0;33;42mI am a Banana!\033[0m"
                // unsigned int squareColor = file->getColor() == Color::Black ? 40 : 47;
                //unsigned int pieceColor = file->getPiece()->getColor() == Color::Black ? 30 : 37;
                // std::cout << "\033[1;" << pieceColor << "m" << (char) file->getPiece()->getType() << "\033[0m|";

            } else {
                std::cout << "  |";
            }
        }
        std::cout << "\n  |--|--|--|--|--|--|--|--|\n";
        //std::cout << '\n';
    }

}

std::string Board::displayStr() {
    std::string display = "    a  b  c  d  e  f  g  h\n  -------------------------\n";

    // Reverse loop so the board starts at 8
    for (int i = 7; i >= 0; --i) {
        auto row = this->squares.at(i);
        display += row.at(0)->getPosition().rank + " |";
        for (auto file : row) {
            if (file->getPiece()) {
                char color = file->getPiece()->getColor() == Color::White ? 'W' : 'B';
                display += color + (char) file->getPiece()->getType() + "|";

                // TODO (maybe?): set foreground and background colors depending on the colors
                // TODO create Color class
                //// "\033[0;33;42mI am a Banana!\033[0m"
                // unsigned int squareColor = file->getColor() == Color::Black ? 40 : 47;
                //unsigned int pieceColor = file->getPiece()->getColor() == Color::Black ? 30 : 37;
                // display << "\033[1;" << pieceColor << "m" << (char) file->getPiece()->getType() << "\033[0m|";

            } else {
                display += "  |";
            }
        }
        display += "\n  |--|--|--|--|--|--|--|--|\n";
    }

    return display;
}



