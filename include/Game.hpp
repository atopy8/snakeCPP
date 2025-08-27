#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Snake.hpp"
#include "Food.hpp"
#include "GameParameters.hpp"
#include "GameScreen.hpp"

/**
 * @brief Classe principale orchestrant le jeu Snake.
 * 
 * Gère l'état du jeu, les entrées clavier, la logique, l'affichage
 * et la communication entre les différents modules (Snake, Food, GameScreen).
 */
class Game
{
private:
    Snake* snake;                ///< Instance du serpent
    Food* food;                  ///< Gestion des nourritures
    GameScreen* mainScreen;      ///< Écran principal (menu)

public:
    GameParameters* param;       ///< Paramètres globaux du jeu

    /**
     * @brief Constructeur
     */
    Game();

    /**
     * @brief Destructeur
     */
    ~Game();

    /**
     * @brief Initialise une nouvelle partie.
     */
    void startGame();

    /**
     * @brief Gère les entrées clavier.
     * @param key Code scancode SFML pressé
     */
    void handleInput(sf::Keyboard::Scancode key);

    /**
     * @brief Dessine l'état courant du jeu dans la fenêtre.
     * @param window Fenêtre de rendu SFML
     */
    void draw(sf::RenderWindow* window);

    /**
     * @brief Met à jour l'état du jeu (logique).
     */
    void update();

    /**
     * @brief Vérifie si le jeu est arrêté.
     * @return true si le serpent est stoppé
     */
    bool isStopped();
};
