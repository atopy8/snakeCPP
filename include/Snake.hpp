#pragma once

#include "SnakeBit.hpp"
#include "Food.hpp"
#include "GameParameters.hpp"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

/**
 * @brief Représente le serpent du jeu Snake.
 * 
 * Gère la structure en liste chaînée du serpent, ses mouvements,
 * sa croissance, ses collisions et son affichage. Le serpent est
 * composé d'une série de SnakeBit reliés entre eux.
 */
class Snake {
private:
    unsigned int size;  ///< Taille actuelle du serpent
    SnakeBit* head;    ///< Pointeur vers la tête du serpent
    SnakeBit* tail;    ///< Pointeur vers la queue du serpent

public:
    /**
     * @brief Constructeur du serpent.
     * 
     * Initialise un serpent avec une taille minimale (tête + quelques segments).
     */
    Snake();

    /**
     * @brief Destructeur du serpent.
     * 
     * Libère la mémoire de tous les segments du serpent.
     */
    ~Snake();

    /**
     * @brief Réinitialise le serpent pour une nouvelle partie.
     * 
     * Remet le serpent à sa taille et position initiales,
     * et configure sa direction par défaut.
     */
    void init();

    /**
     * @brief Change la direction du serpent.
     * 
     * Transmet la nouvelle direction à la tête du serpent,
     * en tenant compte des restrictions de mouvement.
     * 
     * @param dir Nouvelle direction souhaitée
     */
    void changeDirection(SnakeDirection dir);

    /**
     * @brief Met à jour la position de tous les segments.
     * 
     * Propage le mouvement de la tête vers la queue,
     * chaque segment suivant le précédent.
     */
    void update();

    /**
     * @brief Dessine le serpent dans la fenêtre.
     * 
     * Parcourt tous les segments et les affiche sous forme
     * de rectangles dans la grille.
     * 
     * @param param Paramètres du jeu (dimensions, etc.)
     * @param window Fenêtre SFML où dessiner
     */
    void draw(GameParameters* param, sf::RenderWindow* window);

    /**
     * @brief Vérifie si le serpent mange une nourriture et grandit.
     * 
     * Teste si la tête du serpent est sur une nourriture,
     * et ajoute un segment à la queue si c'est le cas.
     * 
     * @param food Gestionnaire des nourritures
     * @param param Paramètres du jeu
     */
    void eatIfFood(Food* food, GameParameters* param);

    /**
     * @brief Vérifie les conditions de mort et arrête le serpent.
     * 
     * Teste les collisions avec les bords et avec le corps du serpent.
     * Arrête le mouvement si une collision est détectée.
     * 
     * @param param Paramètres du jeu (dimensions de la grille)
     * @return true si le serpent est mort, false sinon
     */
    bool stopIfDying(GameParameters* param);

    /**
     * @brief Indique si le serpent est arrêté.
     * 
     * @return true si le serpent ne bouge plus, false s'il est en mouvement
     */
    bool isStopped();
};