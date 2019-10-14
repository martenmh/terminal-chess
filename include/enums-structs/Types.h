//
// Created by root on 10/7/19.
//

#ifndef CHESS_TYPES_H
#define CHESS_TYPES_H

#include <string>

enum Type {
    pawn,
    rook,
    knight,
    bishop,
    queen,
    king
};

// Mainly for debugging purposes
inline std::string typeEnumToStr(int n) {
    std::string s("unknown");
    switch (n) {
        case 0: {
            s = "Pawn";
        }
            break;
        case 1: {
            s = "Rook";
        }
            break;
        case 2: {
            s = "Knight";
        }
            break;
        case 3: {
            s = "Bishop";
        }
            break;
        case 4: {
            s = "Queen";
        }
            break;
        case 5: {
            s = "King";
        }
            break;
    }
    return s;
}

#endif //CHESS_TYPES_H
