#pragma once

#include "SnakeBit.hpp"
#include "Food.hpp"
#include "GameParameters.hpp"
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

    void init();
    void changeDirection(SnakeDirection dir);
    void update();
    void draw(GameParameters* param, sf::RenderWindow* window);
    void eatIfFood(Food* food, GameParameters* param);
    bool stopIfDying(GameParameters* param);
    bool isStopped();
};

