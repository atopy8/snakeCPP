#include <SFML/Graphics.hpp>
#include "../include/Game.hpp"

const unsigned int widthWindow  = 1920u;
const unsigned int heightWindow = 1080u;

const unsigned int nbLin        = 20u;
const unsigned int nbCol        = 80u;

const unsigned int speed        = 10u;


int main()
{
    auto window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "SnakeCPP");
    window.setFramerateLimit(144);

    Game* game   = new Game(speed);
    

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            // Closing the window
            if (event->is<sf::Event::Closed>()){
                window.close();
            }// Key pressed
            else if (const sf::Event::KeyPressed* keyPressed = event->getIf<sf::Event::KeyPressed>()){

                if (keyPressed->scancode == sf::Keyboard::Scancode::Escape){
                    window.close();
                }
                else {
                    game->handleInput(keyPressed->scancode);
                }
            }
        }

        window.clear();
        window.display();
    }
}
