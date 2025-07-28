#pragma once

#include "Position.hpp"

class Food
{
private:
    unsigned int number;
    Position** positionList;

public:
    Food(unsigned int number);
    ~Food();


    bool eatIfFood(unsigned int x, unsigned int y);
    bool isFoodHere(unsigned int x, unsigned int y);
    
    void draw();
};
