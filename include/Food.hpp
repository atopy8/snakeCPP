#pragma once

#include "Position.hpp"
#include "GameParameters.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Food
{
private:
    unsigned int number;
    Position** positionList;

public:
    Food(unsigned int number, GameParameters* param);
    ~Food();


    void init(GameParameters* param);
    void initPosition(Position* position, GameParameters* param, int i, bool isInit);
    bool eatIfFood(unsigned int x, unsigned int y, GameParameters* param);
    bool isFoodHere(unsigned int curIdx, unsigned int x, unsigned int y, bool isInit);
    void draw(GameParameters* param, sf::RenderWindow* window);
};
