#pragma once

#include "GameParameters.hpp"
#include <SFML/Graphics.hpp>
#include <vector>

/**
 * @brief Gère l'écran principal du jeu (menu de navigation).
 * 
 * Cette classe s'occupe de l'affichage du menu principal, de la navigation
 * entre les différentes options et de la gestion des entrées utilisateur
 * dans l'interface du menu.
 */
class GameScreen {
private:

public:
    GameParameters* param;                    ///< Paramètres globaux du jeu
    std::vector<sf::Text> menuItems;         ///< Liste des éléments de menu
    unsigned int idxSelectedElement;         ///< Index de l'élément actuellement sélectionné
    sf::Font font;                          ///< Police utilisée pour le texte du menu
    sf::RectangleShape* square;             ///< Rectangle de sélection (curseur visuel)

    /**
     * @brief Constructeur de l'écran de menu.
     * 
     * Initialise les éléments du menu, charge la police et configure
     * le rectangle de sélection.
     * 
     * @param param Pointeur vers les paramètres globaux du jeu
     */
    GameScreen(GameParameters* param);

    /**
     * @brief Dessine l'écran de menu dans la fenêtre.
     * 
     * Affiche tous les éléments de menu et positionne le rectangle
     * de sélection sur l'élément actuellement choisi.
     * 
     * @param window Fenêtre SFML où dessiner le menu
     */
    void draw(sf::RenderWindow* window);

    /**
     * @brief Gère les entrées clavier dans le menu.
     * 
     * Permet de naviguer dans le menu (haut/bas), de sélectionner
     * des options et d'exécuter les actions correspondantes.
     * 
     * @param keyPressed Code scancode de la touche pressée
     */
    void handleInput(sf::Keyboard::Scancode keyPressed);
};