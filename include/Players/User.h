//
// Created by root on 10/6/19.
//

#ifndef CHESS_USER_H
#define CHESS_USER_H

#include "Player.h"

//explicit Player(Color, std::string);
class User : public Player {
public:
    User(Color, std::string);
};


#endif //CHESS_USER_H
