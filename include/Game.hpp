#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Snake.hpp"
#include "Food.hpp"
#include "GameParameters.hpp"

class Game
{
private:
    Snake* snake;
    Food* food;
    unsigned int speed;

    
public:
    GameParameters* param;
    Game(unsigned int speed, unsigned int numberFood);
    ~Game();

    void startGame();
    void handleInput(sf::Keyboard::Scancode key);
    void draw(sf::RenderWindow* window);
    void update();
};

