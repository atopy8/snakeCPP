#pragma once

/**
 * @file SnakeDirection.hpp
 * @brief Énumération des directions possibles pour le serpent.
 * 
 * Définit toutes les directions de mouvement que peut prendre
 * le serpent dans le jeu, ainsi que l'état d'arrêt.
 */

/**
 * @brief Énumération des directions de mouvement du serpent.
 * 
 * Cette énumération définit les cinq états possibles du serpent :
 * quatre directions cardinales et l'état d'arrêt. Elle est utilisée
 * pour contrôler le mouvement et vérifier les changements de direction
 * valides (empêcher les demi-tours).
 */
enum SnakeDirection {
    STOP = 0, LEFT, RIGHT, UP, DOWN
};
