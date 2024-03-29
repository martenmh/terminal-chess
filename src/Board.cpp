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
            Position pos = position(file, rank);

            Square *square = nullptr;
            // Set user pawns
            if (rank == 2) {
                square = new Square(pos, this,
                                    user->getColor() == Black ? enemy->getPawn(file - 1) : user->getPawn(file - 1));
                // Set ai pawns
            } else if (rank == 7) {
                square = new Square(pos, this,
                                    user->getColor() == Black ? user->getPawn(file - 1) : enemy->getPawn(file - 1));
                // Set ai back row
            } else if (rank == 8) {

                square = setBackRow(pos, user->getColor() == Black ? static_cast<Player *>(user)
                                                                   : static_cast<Player *>(enemy));
                // Set user back row
            } else if (rank == 1) {
                square = setBackRow(pos, user->getColor() == Black ? static_cast<Player *>(enemy)
                                                                   : static_cast<Player *>(user));
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
        // queen..
    } else if (file == 4) {
        return new Square(pos, this, player->getQueen());
        // king.
    } else if (file == 5) {
        return new Square(pos, this, player->getKing());
    }
}

void Board::move(Position from, Position to) {

    Piece *swap;
    Square *prevSquare = this->at(from);
    Square *nextSquare = this->at(to);

    swap = prevSquare->getPiece();
    prevSquare->setEmpty();
    nextSquare->setPiece(swap);
    swap->setPosition(nextSquare->getPosition());
}

Square *Board::at(Position pos) {
    return this->squares.at(pos.rank).at(pos.file);
}

#include "Game.h"
void Board::display() {

    // TODO Display moves on the side of the board

    /*
         a  b  c  d  e  f  g  h            Bot: P N
       -------------------------           __________
     8 |BR|BN|BB|BK|BQ|BB|BN|BR|           1. e4 e5
       |--|--|--|--|--|--|--|--|           2. Nf3 Nc6
     7 |BP|BP|BP|BP|BP|BP|BP|BP|           3. Bb5 a6
       |--|--|--|--|--|--|--|--|           4. Rxd4 ..
     6 |  |  |  |  |  |  |  |  |
       |--|--|--|--|--|--|--|--|           __________
     5 |  |  |  |  |  |  |  |  |           Player: P R P P
       |--|--|--|--|--|--|--|--|
     4 |  |  |  |  |  |  |  |  |
       |--|--|--|--|--|--|--|--|
     3 |  |  |  |  |  |  |  |  |
       |--|--|--|--|--|--|--|--|
     2 |WP|WP|WP|WP|WP|WP|WP|WP|
       |--|--|--|--|--|--|--|--|
     1 |WR|WN|WB|WK|WQ|WB|WN|WR|
       -------------------------
     : Rxd4

     */

    Game::displayPlayer(enemy);

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
        if (i == 0) {
            std::cout << "\n  -------------------------\n";
            break;
        }

        std::cout << "\n  |--|--|--|--|--|--|--|--|\n";

    }

    Game::displayPlayer(static_cast<Player *>(user));
}

bool Board::positionOutOfBounds(int rank, int file) {
    return (file < 1 || file > 8 || rank < 1 || rank > 8);
}

bool Board::positionOutOfBounds(Position pos) {
    return (static_cast<int>(pos.file) < 1 || static_cast<int>(pos.file) > 8 || pos.rank < 1 || pos.rank > 8);
}

std::vector<Position> Board::positionsBetween(Position fp, Position lp) {
    std::vector<Position> positions;
    bool fpRankLarger = fp.rank > lp.rank;
    bool fpFileLarger = fp.file > lp.file;

    // Set the positions 1 more to each other, so every position returned is 'between' the two position.
    fp.file = static_cast<HorizontalPosition>(fpFileLarger ? fp.file - 1 : fp.file + 1);
    fp.rank = fpRankLarger ? fp.rank - 1 : fp.rank + 1;

    // If they are on the same rank (horizontal alignment)
    if (fp.rank == lp.rank)
        for (int i = fp.file; i != lp.file; fpFileLarger ? i-- : i++)
            positions.push_back(position(i, fp.rank));

    // If they are on the same file (vertical alignment)
    if (fp.file == lp.file)
        for (int i = fp.rank; i != lp.rank; fpRankLarger ? i-- : i++)
            positions.push_back(position(i, fp.rank));

    // If they are on the same diagonal line (diagonal alignment..)
    if (fp.file + fp.rank % 2 == lp.file + lp.rank) {
        // One variable for the rank & one for the file. if the rank is larger than the other than decrease the rank and vice versa.
        // The same goes for the file
        for (int i = fp.rank, ii = fp.file;
             i != lp.rank && ii != lp.file; fpRankLarger ? i-- : i++, fpFileLarger ? ii-- : ii++)
            positions.push_back(position(i, fp.rank));
    }
    return std::vector<Position>();
}



