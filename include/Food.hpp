#pragma once

#include "Position.hpp"
#include "GameParameters.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

/// @brief Gère les nourritures du Snake (positions, détection, affichage).
class Food
{
private:
    unsigned int number;       ///< Nombre de nourritures.
    Position** positionList;   ///< Tableau dynamique de positions.

public:
    /// @brief Construit et place `number` nourritures aléatoires.
    /// @param number nombre de nourritures
    /// @param param paramètres du jeu
    Food(unsigned int number, GameParameters* param);

    /// @brief Libère la mémoire des positions.
    ~Food();

    /// @brief Réinitialise toutes les nourritures.
    /// @param param paramètres du jeu
    void init(GameParameters* param);

    /// @brief Place une nourriture aléatoirement (évite les doublons).
    /// @param position pointeur vers la position à remplir
    /// @param param paramètres du jeu
    /// @param i indice de la nourriture
    /// @param isInit vrai si c'est l'initialisation (permet d'éviter les conflits partiels)
    void initPosition(Position* position, GameParameters* param, int i, bool isInit);

    /// @brief Vérifie si (x,y) contient une nourriture, puis la replace si mangée.
    /// @param x colonne
    /// @param y ligne
    /// @param param paramètres du jeu
    /// @return true si une nourriture a été mangée
    bool eatIfFood(unsigned int x, unsigned int y, GameParameters* param);

    /// @brief Vérifie si une autre nourriture est déjà sur (x,y).
    /// @param curIdx indice courant de la nourriture à placer
    /// @param x colonne
    /// @param y ligne
    /// @param isInit vrai si on est en phase d'init
    /// @return true si une nourriture occupe déjà la case
    bool isFoodHere(unsigned int curIdx, unsigned int x, unsigned int y, bool isInit);

    /// @brief Dessine toutes les nourritures.
    /// @param param paramètres du jeu
    /// @param window fenêtre SFML où dessiner
    void draw(GameParameters* param, sf::RenderWindow* window);
};
