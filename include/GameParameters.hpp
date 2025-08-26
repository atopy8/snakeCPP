#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class GameParameters{
    private:
    public:
        unsigned int widthWindow  = 1920u;
        unsigned int heightWindow = 1080u;

        unsigned int nbLin        = 22u;
        unsigned int nbCol        = 40u;
        unsigned int nbFood       = 10u;

        unsigned int updateSpeed  = 100000u;
        bool wantStart            = false;
        sf::RenderWindow *window;

};