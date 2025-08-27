#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

/**
 * @brief Structure contenant tous les paramètres globaux du jeu.
 * 
 * Cette classe centralise la configuration du jeu, incluant les dimensions
 * de la fenêtre, la taille de la grille, les paramètres de gameplay
 * et l'état du jeu.
 */
class GameParameters {
private:

public:
    unsigned int widthWindow  = 1920u;  ///< Largeur de la fenêtre en pixels
    unsigned int heightWindow = 1080u;  ///< Hauteur de la fenêtre en pixels

    unsigned int nbLin        = 22u;    ///< Nombre de lignes de la grille
    unsigned int nbCol        = 40u;    ///< Nombre de colonnes de la grille
    unsigned int nbFood       = 10u;    ///< Nombre de nourritures simultanées

    unsigned int updateSpeed  = 100000u;  ///< Vitesse de mise à jour (en microsecondes)
    bool wantStart            = false;    ///< Indique si l'utilisateur veut démarrer une partie
    sf::RenderWindow* window;            ///< Pointeur vers la fenêtre SFML principale
};