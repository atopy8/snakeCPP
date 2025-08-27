#include "../include/GameScreen.hpp"
#include <string>
#include <iostream>

/**
 * @brief Énumération des options du menu principal.
 */
typedef enum {
    START_GAME = 0,    ///< Démarrer une partie
    GRID_SIZE,         ///< Modifier la taille de la grille
    UPDATE_TIME,       ///< Modifier le temps de mise à jour
    FOOD_NUMBER,       ///< Modifier le nombre de nourritures
    QUIT              ///< Quitter le jeu
} MainScreenSelection;

/**
 * @brief Constructeur de GameScreen.
 * 
 * Initialise l'écran de menu avec les options disponibles,
 * charge la police et configure le rectangle de sélection.
 * 
 * @param gameParam Pointeur vers les paramètres globaux du jeu
 */
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
    
    // Chargement de la police pour le menu
    if (!font.openFromFile("../assets/ARIAL.TTF")) {
        std::cerr << "Erreur: impossible de charger la police ARIAL.TTF\n";
        return;
    }
    
    // Création des éléments de texte du menu
    for (std::size_t i = 0; i < options.size(); i++) {
        sf::Text text(font, options[i], 40);
        text.setPosition(sf::Vector2f{300.f, 150.f + 60.f * static_cast<float>(i)});
        menuItems.push_back(text);
    }
    
    // Configuration du rectangle de sélection
    unsigned int nbLin = param->nbLin;
    unsigned int nbCol = param->nbCol;
    unsigned int width = param->widthWindow;
    unsigned int height = param->heightWindow;

    sf::Vector2f sizeSquare(width / (nbCol * 2), height / (nbLin * 2));
    square = new sf::RectangleShape(sizeSquare);
    sf::Color color(sf::Color::White);
    sf::Vector2f posSquare(250.f, 164.f);
    square->setFillColor(color);
    square->setPosition(posSquare);
}

/**
 * @brief Dessine l'écran de menu.
 * 
 * Positionne le rectangle de sélection sur l'élément actuel
 * et dessine tous les éléments du menu.
 * 
 * @param window Fenêtre SFML où effectuer le rendu
 */
void GameScreen::draw(sf::RenderWindow* window) {
    // Positionnement du rectangle de sélection
    sf::Vector2f posSquare(250.f, 164.f + 60.f * idxSelectedElement);
    square->setPosition(posSquare);
    window->draw(*square);
    
    // Dessin des éléments de menu
    for (const sf::Text& item : menuItems) { 
        window->draw(item);
    }
}

/**
 * @brief Gère les entrées clavier dans le menu.
 * 
 * Permet la navigation verticale avec W/S, et l'activation
 * d'options avec Entrée. Les touches A/D sont réservées
 * pour de futures fonctionnalités.
 * 
 * @param keyPressed Code scancode de la touche pressée
 */
void GameScreen::handleInput(sf::Keyboard::Scancode keyPressed) {
    if (keyPressed == sf::Keyboard::Scancode::W) {
        // Navigation vers le haut (avec boucle)
        if (idxSelectedElement != 0) {
            idxSelectedElement = (idxSelectedElement - 1);
        } else {
            idxSelectedElement = 4;
        }
    }
    else if (keyPressed == sf::Keyboard::Scancode::S) {
        // Navigation vers le bas (avec boucle)
        idxSelectedElement = (idxSelectedElement + 1) % 5;
    }
    else if (keyPressed == sf::Keyboard::Scancode::A) {
        // Réservé pour navigation horizontale future
    }
    else if (keyPressed == sf::Keyboard::Scancode::D) {
        // Réservé pour navigation horizontale future
    }
    else if (keyPressed == sf::Keyboard::Scancode::Enter) {
        // Activation de l'option sélectionnée
        switch (idxSelectedElement) {
            case START_GAME:
                param->wantStart = true;
                break;
            case QUIT:
                param->window->close();
                break;
            default:
                // Autres options non implémentées
                break;
        }
    }
    
    // Mise à jour immédiate de l'affichage
    draw(param->window);
}