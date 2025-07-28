#pragma once

#include <SFML/Graphics.hpp>
#include "Snake.hpp"
#include "Food.hpp"

class Game
{
private:
    Snake snake;
    Food food;
    unsigned int speed;
public:
    Game(unsigned int speed);
    ~Game();

    void handleInput(sf::Keyboard::Scancode key);
};

