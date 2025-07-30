#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "SnakeDirection.hpp"
#include "Position.hpp"
#include "GameParameters.hpp"

class SnakeBit
{
private:
    
    
public:
    Position pos;
    SnakeBit* next;
    SnakeBit* prec;
    SnakeDirection dir;
    SnakeDirection nextDir;

    SnakeBit(SnakeBit* prec);
    ~SnakeBit();

    void changeDirection(SnakeDirection dir);
    void move();
    void update();
    void draw(GameParameters* param, sf::RenderWindow* window);
    
};