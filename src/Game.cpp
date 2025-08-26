#include "../include/Game.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

Game::Game(unsigned int speedInit, unsigned int numberFood){
    speed = speedInit;
    param = new GameParameters();
    snake = new Snake();
    food = new Food(numberFood, param);
    mainScreen = new GameScreen(param); 
    
    }

Game::~Game(){
    snake->~Snake();
    food->~Food();

}

void Game::handleInput(sf::Keyboard::Scancode keyPressed)
{
    if (isStopped()){
        mainScreen->handleInput(keyPressed);
    }else{
        if (keyPressed == sf::Keyboard::Scancode::W) {
            // move up
            std::cout << "up\n";
            snake->changeDirection(UP);
        }
        else if (keyPressed == sf::Keyboard::Scancode::S) {
            // move down
            std::cout << "down\n";
            snake->changeDirection(DOWN);
        }
        else if (keyPressed == sf::Keyboard::Scancode::A) {
            // move left
            std::cout << "left\n";
            snake->changeDirection(LEFT);
        }
        else if (keyPressed == sf::Keyboard::Scancode::D) {
            // move right
            std::cout << "right\n";
            snake->changeDirection(RIGHT);
        }
    }
}

void Game::startGame() {
    // initialisation snake
    snake->init();
    // initialisation food
    food->init(param);
    param->wantStart = false;
}

void Game::draw(sf::RenderWindow* window) {
    if (isStopped()){
        mainScreen->draw(window);
    }else{
        snake->draw(param, window);
        food->draw(param, window);
    }
    
}

void Game::update(){
    if (isStopped()){
        if (!param->wantStart) return;
        else startGame();
    }else{
        snake->eatIfFood(food, param);
        snake->update();
        snake->stopIfDying(param);
    }
    
    
}

bool Game::isStopped(){
    return snake->isStopped();
}