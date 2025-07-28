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
    unsigned int terrain[20][80];
public:
    Game(unsigned int speed, unsigned int numberFood);
    ~Game();

    void startGame();
    void handleInput(sf::Keyboard::Scancode key);
    void draw();
    void drawTerrain();  
};

