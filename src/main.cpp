#include <SFML/Graphics.hpp>
// clock
#include <SFML/System/Export.hpp>
#include <chrono>
#include <ratio>
#include <type_traits>

#include "../include/Game.hpp"

const unsigned int widthWindow  = 1920u;
const unsigned int heightWindow = 1080u;

const unsigned int nbLin        = 20u;
const unsigned int nbCol        = 80u;

const unsigned int speed        = 10u;
const unsigned int nbFood       = 1u;

const unsigned int updateSpeed  = 50u;


int main()
{
    auto window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "SnakeCPP");
    window.setFramerateLimit(144);

    Game* game   = new Game(speed, nbFood);
    time_t lastTime;
    time(&lastTime);

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

        
        // visual update
        if (difftime(time(nullptr), lastTime) > updateSpeed) {
            
            window.clear();
            
            
            time(&lastTime);
            game->draw();


            window.display();
        }
        
    }
}
