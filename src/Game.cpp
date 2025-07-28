#include "../include/Game.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

Game::Game(unsigned int speedInit)
    : 
    speed(speedInit),
    snake(Snake()),
    food(Food()) 
    {}

Game::~Game() = default;

void Game::handleInput(sf::Keyboard::Scancode keyPressed)
{
    if (keyPressed == sf::Keyboard::Scancode::W) {
        // move up
        std::cout << "up\n";
    }
    else if (keyPressed == sf::Keyboard::Scancode::S) {
        // move down
        std::cout << "down\n";
    }
    else if (keyPressed == sf::Keyboard::Scancode::A) {
        // move left
        std::cout << "left\n";
    }
    else if (keyPressed == sf::Keyboard::Scancode::D) {
        // move right
        std::cout << "right\n";
    }
}