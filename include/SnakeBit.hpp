#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "SnakeDirection.hpp"
#include "Position.hpp"
#include "GameParameters.hpp"

/**
 * @brief Représente un segment individuel du serpent.
 * 
 * Chaque SnakeBit est un élément d'une liste chaînée doublement liée
 * qui forme le corps du serpent. Il gère sa position, sa direction
 * et sa relation avec les segments adjacents.
 */
class SnakeBit {
private:
    
public:
    Position pos;              ///< Position actuelle du segment dans la grille
    SnakeBit* next;           ///< Pointeur vers le segment suivant (vers la queue)
    SnakeBit* prec;           ///< Pointeur vers le segment précédent (vers la tête)
    SnakeDirection dir;       ///< Direction actuelle du segment
    SnakeDirection nextDir;   ///< Prochaine direction (pour la tête uniquement)

    /**
     * @brief Constructeur d'un segment de serpent.
     * 
     * Crée un nouveau segment et l'insère dans la liste chaînée
     * après le segment précédent. Hérite de la position et direction
     * du segment précédent s'il existe.
     * 
     * @param prec Pointeur vers le segment précédent (plus proche de la tête)
     */
    SnakeBit(SnakeBit* prec);

    /**
     * @brief Destructeur du segment.
     */
    ~SnakeBit();

    /**
     * @brief Change la direction du segment.
     * 
     * Vérifie que le changement de direction est valide (pas de demi-tour)
     * et met à jour nextDir en conséquence. Utilisé principalement pour la tête.
     * 
     * @param dir Nouvelle direction souhaitée
     */
    void changeDirection(SnakeDirection dir);

    /**
     * @brief Déplace le segment selon sa direction actuelle.
     * 
     * Met à jour la position du segment en fonction de sa direction.
     * Applique d'abord nextDir à dir, puis effectue le déplacement.
     * Utilisé principalement pour la tête du serpent.
     */
    void move();

    /**
     * @brief Met à jour le segment en suivant le segment précédent.
     * 
     * Copie la position et la direction du segment précédent.
     * Utilisé pour tous les segments du corps (pas la tête).
     */
    void update();

    /**
     * @brief Dessine le segment dans la fenêtre.
     * 
     * Affiche le segment sous forme d'un rectangle blanc
     * dans la case correspondante de la grille.
     * 
     * @param param Paramètres du jeu pour les dimensions d'affichage
     * @param window Fenêtre SFML où dessiner le segment
     */
    void draw(GameParameters* param, sf::RenderWindow* window);
};