#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "SnakeDirection.hpp"
#include "Position.hpp"

class SnakeBit
{
private:
    
    Position* pos;
public:
    SnakeBit* next;
    SnakeBit* prec;
    SnakeDirection dir;

    SnakeBit(SnakeBit* prec);
    ~SnakeBit();

    void changeDirection(SnakeDirection dir);
    void moveToward(SnakeDirection dir);
    void update();
    void draw(sf::RenderWindow* window);
    
};