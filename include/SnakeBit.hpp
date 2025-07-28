#pragma once

#include "SnakeDirection.hpp"
#include "Position.hpp"

class SnakeBit
{
private:
    SnakeDirection dir;
    SnakeBit* next;
    SnakeBit* prec;
    Position* pos;
public:
    SnakeBit(SnakeBit* prec);
    ~SnakeBit();

    void update();
    void draw();
};