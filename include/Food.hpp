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


    bool eatIfFood(unsigned int x, unsigned int y, GameParameters* param);
    bool isFoodHere(unsigned int curIdx, unsigned int x, unsigned int y);
    bool isFoodHereInit(unsigned int curIdx, unsigned int x, unsigned int y);
    void draw(GameParameters* param, sf::RenderWindow* window);
};
