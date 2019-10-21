//
// Created by root on 10/7/19.
//

#ifndef CHESS_POSITION_H
#define CHESS_POSITION_H


enum HorizontalPosition {
    a,
    b,
    c,
    d,
    e,
    f,
    g,
    h
};

// Mainly for debugging purposes
static inline char fileToStr(int n) {
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

// Mainly for debugging purposes
static inline int strToFile(char n) {
    int s = 0;
    switch (n) {
        case 1: {
            s = 1;
        }
            break;
        case 2: {
            s = 2;
        }
            break;
        case 3: {
            s = 3;
        }
            break;
        case 4: {
            s = 4;
        }
            break;
        case 5: {
            s = 5;
        }
            break;
        case 6: {
            s = 6;
        }
            break;
        case 7: {
            s = 7;
        }
            break;
        case 8: {
            s = 8;
        }
            break;
    }
    return s;
}

struct Position {
    // a to h
    HorizontalPosition file;
    // 1 to 8
    int rank;


    // strToFile() to make sure the files are numbers & not characters
    inline Position operator+(Position other) {
        return Position{static_cast<HorizontalPosition >(strToFile(file) + strToFile(other.file)), rank + other.rank};
    }
};

inline Position position(int file, int rank) {
    return Position{static_cast<HorizontalPosition>(file), rank};
}


#endif //CHESS_POSITION_H
