//
// Created by root on 10/7/19.
//

#ifndef CHESS_POSITION_H
#define CHESS_POSITION_H


enum HorizontalPosition {
    a = 1,
    b = 2,
    c = 3,
    d = 4,
    e = 5,
    f = 6,
    g = 7,
    h = 8
};

struct Position {
    // a to h
    HorizontalPosition file;
    // 1 to 8
    unsigned int rank;
};

// Mainly for debugging purposes
inline char fileToStr(int n) {
    char s('\0');
    switch (n) {
        case 1: {
            s = 'a';
        }
            break;
        case 2: {
            s = 'b';
        }
            break;
        case 3: {
            s = 'c';
        }
            break;
        case 4: {
            s = 'd';
        }
            break;
        case 5: {
            s = 'e';
        }
            break;
        case 6: {
            s = 'f';
        }
            break;
        case 7: {
            s = 'g';
        }
            break;
        case 8: {
            s = 'h';
        }
            break;
    }
    return s;
}




#endif //CHESS_POSITION_H
