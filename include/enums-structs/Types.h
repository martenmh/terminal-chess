//
// Created by root on 10/7/19.
//

#ifndef CHESS_TYPES_H
#define CHESS_TYPES_H

#include <string>

enum Type {
    pawn = 'P',
    rook = 'R',
    knight = 'N',
    bishop = 'B',
    queen = 'Q',
    king = 'K'
};

// Returns the accompanying
inline std::string typeEnumToStr(int n) {
    std::string s("unknown");
    switch (n) {
        case 0: {
            s = "P";
        }
            break;
        case 1: {
            s = "R";
        }
            break;
        case 2: {
            s = "N";
        }
            break;
        case 3: {
            s = "B";
        }
            break;
        case 4: {
            s = "Q";
        }
            break;
        case 5: {
            s = "K";
        }
            break;
    }
    return s;
}

#endif //CHESS_TYPES_H
