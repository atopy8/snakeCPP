/**
 * @file main.cpp
 * @brief Point d'entrée principal du jeu Snake en C++ avec SFML.
 * 
 * Ce fichier contient la boucle principale du jeu, la gestion des événements
 * et la configuration des constantes de jeu.
 */

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "../include/Game.hpp"


/**
 * @brief Point d'entrée principal du programme.
 * 
 * Initialise la fenêtre SFML avec anticrénelage, crée l'instance
 * de jeu et lance la boucle principale. Gère les événements
 * système et utilisateur, puis effectue la mise à jour et
 * le rendu à intervalle régulier.
 * 
 * @return 0 si l'exécution s'est déroulée normalement
 */
int main() {
    // Configuration de l'anticrénelage pour un rendu plus lisse
    sf::ContextSettings settings;
    settings.antiAliasingLevel = 8;

    // Création de la fenêtre avec les paramètres définis
    sf::RenderWindow window = sf::RenderWindow(
        sf::VideoMode({1920u, 1080u}), 
        "SnakeCPP", 
        sf::Style::Default, 
        sf::State::Windowed, 
        settings
    );
    window.setFramerateLimit(144);  // Limitation à 144 FPS

    // Initialisation du jeu et liaison avec la fenêtre
    Game* game = new Game();
    game->param->window = &window;
    
    // Variable pour gérer le timing des mises à jour
    time_t lastTime = clock();

    // ===== BOUCLE PRINCIPALE DU JEU =====
    while (window.isOpen()) {
        // ===== GESTION DES ÉVÉNEMENTS =====
        while (auto event = window.pollEvent()) {
            // Fermeture de la fenêtre
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
            // Gestion des touches pressées
            else if (const sf::Event::KeyPressed* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
                if (keyPressed->scancode == sf::Keyboard::Scancode::Escape) {
                    // Échap ferme l'application
                    window.close();
                } else {
                    // Transmission de l'input au jeu
                    game->handleInput(keyPressed->scancode);
                }
            }
        }

        // ===== MISE À JOUR ET RENDU =====
        auto clockTime = clock(); 
        if ((clockTime - lastTime) > game->param->updateSpeed) {
            // Mise à jour de la logique de jeu
            game->update();
            
            // Effacement de l'écran précédent
            window.clear();
            
            // Mise à jour du timer
            lastTime = clock();
            
            // Rendu du nouvel état
            game->draw(&window);

            // Affichage à l'écran
            window.display();
        }
    }

    return 0;
}