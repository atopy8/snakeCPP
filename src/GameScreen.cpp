#include "../include/GameScreen.hpp"
#include <string>
#include <iostream>

typedef enum {START_GAME = 0, GRID_SIZE, UPDATE_TIME, FOOD_NUMBER, QUIT} MainScreenSelection;

GameScreen::GameScreen(GameParameters* gameParam) {
    param = gameParam;
    idxSelectedElement = 0;
    
    std::vector<std::string> options = {
        "Start Game",
        "Grid Size", 
        "Update Time",
        "Food Number",
        "Quit"
    };
    
    if (!font.openFromFile("../assets/ARIAL.TTF")) {
        std::cerr << "Erreur: impossible de charger la police ARIAL.TTF\n";
        return;
    }
    
    for (std::size_t i = 0; i < options.size(); i++) {
        sf::Text text(font, options[i], 40);
        text.setPosition(sf::Vector2f{300.f, 150.f + 60.f * static_cast<float>(i)});
        menuItems.push_back(text);
    }
    
    unsigned int nbLin = param->nbLin;
    unsigned int nbCol = param->nbCol;
    unsigned int width = param->widthWindow;
    unsigned int height= param->heightWindow;

    sf::Vector2f sizeSquare(width / (nbCol*2) , height / (nbLin*2));
    square = new sf::RectangleShape(sizeSquare);
    sf::Color color(sf::Color::White);
    sf::Vector2f posSquare(250.f, 164.f);
    square->setFillColor(color);
    square->setPosition(posSquare);
}

void GameScreen::draw(sf::RenderWindow* window) {
    sf::Vector2f posSquare(250.f, 164.f + 60.f * idxSelectedElement);
    square->setPosition(posSquare);
    window->draw(*square);
    for (const sf::Text& item : menuItems) { 
        window->draw(item);
    }
}


void GameScreen::handleInput(sf::Keyboard::Scancode keyPressed){
    if (keyPressed == sf::Keyboard::Scancode::W) {
        if (idxSelectedElement != 0)    idxSelectedElement = (idxSelectedElement-1);
        else                            idxSelectedElement = 4;
    }
    else if (keyPressed == sf::Keyboard::Scancode::S) {
        idxSelectedElement = (idxSelectedElement+1)%5;
    }
    else if (keyPressed == sf::Keyboard::Scancode::A) {

    }
    else if (keyPressed == sf::Keyboard::Scancode::D) {
        
    }
    else if (keyPressed == sf::Keyboard::Scancode::Enter) {
        switch (idxSelectedElement)
        {
        case START_GAME:
            param->wantStart = true;
            break;
        case QUIT:
            param->window->close();
            break;
        default:
            break;
        }

    }
    draw(param->window);
}