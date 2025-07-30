#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>


#include "../include/Game.hpp"

const unsigned int widthWindow  = 1920u;
const unsigned int heightWindow = 1080u;

const unsigned int nbLin        = 45u;
const unsigned int nbCol        = 80u;

const unsigned int speed        = 10u;
const unsigned int nbFood       = 10u;

const unsigned int updateSpeed  = 100000u;


int main()
{


    sf::ContextSettings settings;
    settings.antiAliasingLevel = 8;


    sf::RenderWindow window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "SnakeCPP", sf::Style::Default, sf::State::Windowed, settings);
    window.setFramerateLimit(144);

    Game* game   = new Game(speed, nbFood);
    time_t lastTime = clock();

    while (window.isOpen())
    {
        while (auto event = window.pollEvent())
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
        auto clockTime = clock(); 
        if ((clockTime - lastTime) > game->param->updateSpeed) {
            
            game->update();
            
            window.clear();
            
            
            lastTime = clock();
            game->draw(&window);


            window.display();
        }
        
    }
}
