//
// Created by root on 10/6/19.
//

#ifndef CHESS_PLAYER_H
#define CHESS_PLAYER_H

#include <string>
enum Color{
    White,
    Black
};

class Player {
public:
    explicit Player(Color);
private:
    Color color;
    std::string name;
};


#endif //CHESS_PLAYER_H
