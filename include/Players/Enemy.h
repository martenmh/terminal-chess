//
// Created by root on 10/6/19.
//

#ifndef CHESS_ENEMY_H
#define CHESS_ENEMY_H

#include "Player.h"

class Enemy : public Player {
public:
    Enemy(Color = Color::Black, std::string = "Bot");
};


#endif //CHESS_ENEMY_H
