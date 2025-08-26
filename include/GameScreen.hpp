#pragma once



#include "GameParameters.hpp"

#include <SFML/Graphics.hpp>
#include <vector>


class GameScreen{
    private:
    public:
        GameParameters* param;
        std::vector<sf::Text> menuItems;
        unsigned int idxSelectedElement;
        sf::Font font;
        sf::RectangleShape* square;

        GameScreen(GameParameters* param);

        void draw(sf::RenderWindow* window);
        void handleInput(sf::Keyboard::Scancode keyPressed);
};