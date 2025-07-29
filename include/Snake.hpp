#pragma once

#include "SnakeBit.hpp"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Snake
{
private:
    unsigned int size;
    SnakeBit* head;
    SnakeBit* tail;
public:
    Snake();
    ~Snake();

    void changeDirection(SnakeDirection dir);
    void update();
    void draw(sf::RenderWindow* window);
};

