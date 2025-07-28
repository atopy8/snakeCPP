#include "../include/Game.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

Game::Game(unsigned int speedInit, unsigned int numberFood)
    : 
    speed(speedInit),
    snake(Snake()),
    food(Food(numberFood)) 
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

void Game::startGame() {
    // initialisation terrain
    // initialisation snake
    // initialisation food
    // drawing
}

void Game::draw() {
    this->drawTerrain();
    snake.draw();
    food.draw();
}