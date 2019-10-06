//
// Created by root on 10/6/19.
//

#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

#include <vector>
class Square;

enum HorizontalPosition{
    a = 1,
    b,
    c,
    d,
    e,
    f,
    g,
    h
};

struct Position{
    // a to h
    HorizontalPosition horizontalPosition;
    // 1 to 8
    unsigned int verticalPosition;
};

class Board {
public:
    Board();
private:
    // 64 (8 (1 to 8) * 8 (a to h)) Squares
    std::vector<std::vector<Square>> squares;
};


#endif //CHESS_BOARD_H
