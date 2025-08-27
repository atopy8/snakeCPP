#include "../include/Game.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

/**
 * @brief Constructeur de la classe Game.
 * 
 * Initialise tous les composants du jeu : paramètres globaux,
 * serpent, nourritures et écran de menu. Configure la vitesse
 * initiale et le nombre de nourritures.
 * 
 * @param speedInit Vitesse de mise à jour initiale
 * @param numberFood Nombre de nourritures à placer sur la grille
 */
Game::Game() {
    param = new GameParameters();        // Paramètres globaux du jeu
    snake = new Snake();                 // Instance du serpent
    food = new Food(param->nbFood, param);  // Gestionnaire des nourritures
    mainScreen = new GameScreen(param);  // Écran de menu principal
}

/**
 * @brief Destructeur de la classe Game.
 * 
 * Libère la mémoire allouée pour le serpent et les nourritures.
 * Note: Appel explicite du destructeur (non recommandé, utiliser delete).
 */
Game::~Game() {
    snake->~Snake();
    food->~Food();
}

/**
 * @brief Gère les entrées clavier selon l'état du jeu.
 * 
 * Redirige les entrées vers le menu si le jeu est arrêté,
 * ou vers les contrôles du serpent pendant le jeu.
 * 
 * @param keyPressed Code scancode SFML de la touche pressée
 */
void Game::handleInput(sf::Keyboard::Scancode keyPressed) {
    if (isStopped()) {
        // Mode menu : délégation à l'écran principal
        mainScreen->handleInput(keyPressed);
    } else {
        // Mode jeu : contrôle du serpent
        if (keyPressed == sf::Keyboard::Scancode::W) {
            // Déplacement vers le haut
            std::cout << "up\n";
            snake->changeDirection(UP);
        }
        else if (keyPressed == sf::Keyboard::Scancode::S) {
            // Déplacement vers le bas
            std::cout << "down\n";
            snake->changeDirection(DOWN);
        }
        else if (keyPressed == sf::Keyboard::Scancode::A) {
            // Déplacement vers la gauche
            std::cout << "left\n";
            snake->changeDirection(LEFT);
        }
        else if (keyPressed == sf::Keyboard::Scancode::D) {
            // Déplacement vers la droite
            std::cout << "right\n";
            snake->changeDirection(RIGHT);
        }
    }
}

/**
 * @brief Démarre une nouvelle partie.
 * 
 * Réinitialise le serpent et les nourritures à leur état initial,
 * puis désactive le flag de demande de démarrage.
 */
void Game::startGame() {
    // Réinitialisation du serpent
    snake->init();
    // Réinitialisation des nourritures
    food->init(param);
    // Désactivation du flag de démarrage
    param->wantStart = false;
}

/**
 * @brief Dessine l'état actuel du jeu.
 * 
 * Affiche soit l'écran de menu (si arrêté), soit le serpent
 * et les nourritures (pendant le jeu).
 * 
 * @param window Fenêtre SFML où effectuer le rendu
 */
void Game::draw(sf::RenderWindow* window) {
    if (isStopped()) {
        // Affichage du menu principal
        mainScreen->draw(window);
    } else {
        // Affichage du jeu en cours
        snake->draw(param, window);
        food->draw(param, window);
    }
}

/**
 * @brief Met à jour la logique du jeu.
 * 
 * Gère deux modes : menu (attend le démarrage) ou jeu actif
 * (mise à jour du serpent, nourriture, détection de collision).
 */
void Game::update() {
    if (isStopped()) {
        // Mode arrêté : vérification de demande de démarrage
        if (!param->wantStart) return;
        else startGame();
    } else {
        // Mode jeu actif : logique de gameplay
        snake->eatIfFood(food, param);  // Vérification nourriture mangée
        snake->update();                // Mise à jour position serpent
        snake->stopIfDying(param);      // Vérification collisions mortelles
    }
}

/**
 * @brief Indique si le jeu est en état d'arrêt.
 * 
 * @return true si le serpent est arrêté, false s'il est en mouvement
 */
bool Game::isStopped() {
    return snake->isStopped();
}