//
// Created by root on 10/7/19.
//

#ifndef CHESS_POSITION_H
#define CHESS_POSITION_H


enum HorizontalPosition {
    a = 1,
    b,
    c,
    d,
    e,
    f,
    g,
    h
};

struct Position {
    // a to h
    HorizontalPosition horizontalPosition;
    // 1 to 8
    unsigned int verticalPosition;
};


#endif //CHESS_POSITION_H
