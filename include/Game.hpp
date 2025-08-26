#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Snake.hpp"
#include "Food.hpp"
#include "GameParameters.hpp"
#include "GameScreen.hpp"

class Game
{
private:
    Snake* snake;
    Food* food;
    GameScreen* mainScreen;
    unsigned int speed;


    
public:
    GameParameters* param;
    Game(unsigned int speed, unsigned int numberFood);
    ~Game();

    void startGame();
    void handleInput(sf::Keyboard::Scancode key);
    void draw(sf::RenderWindow* window);
    void update();
    bool isStopped();
};

