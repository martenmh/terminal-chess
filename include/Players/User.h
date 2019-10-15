//
// Created by root on 10/6/19.
//

#ifndef CHESS_USER_H
#define CHESS_USER_H

#include "Player.h"

//explicit Player(Color, std::string);
class User : public Player {
public:
    User(Color = Color::White, std::string = "Player");

    // TODO: Get either the descriptive or algebraic notation and play the piece
    bool set(std::string);
};


#endif //CHESS_USER_H
