#include <stdlib.h>
#include "../include/Food.hpp"

/**
 * @brief Initialise une position aléatoire pour un aliment.
 * 
 * Génère une position dans les bornes de la grille,
 * et vérifie qu’elle n’entre pas en collision avec une autre nourriture.
 * 
 * @param position Référence vers la position à initialiser
 * @param param Paramètres globaux du jeu
 * @param i Index courant
 * @param isInit Indique si c’est la phase d’initialisation
 */
void Food::initPosition(Position* position, GameParameters* param, int i, bool isInit) {
    position->x = rand() % param->nbCol - 1;
    position->y = rand() % param->nbLin - 1;
    while (isFoodHere(i, position->x, position->y, isInit)) {
        position->x = rand() % param->nbCol - 1;
        position->y = rand() % param->nbLin - 1;
    }
}

/**
 * @brief Constructeur de Food
 * 
 * Alloue la liste des positions et les initialise aléatoirement.
 * 
 * @param number Nombre de nourritures
 * @param param Paramètres globaux
 */
Food::Food(unsigned int number, GameParameters* param)
    : number(number) {
    positionList = new Position*[number];
    for (int i = 0; i < number; i++) {
        positionList[i] = new Position;
        initPosition(positionList[i], param, i, true);
    }
}

/**
 * @brief Destructeur de Food
 */
Food::~Food() {
    delete[] positionList;
}

/**
 * @brief Vérifie si une nourriture est mangée et la réinitialise si besoin.
 * 
 * @param x Position X de la tête
 * @param y Position Y de la tête
 * @param param Paramètres globaux
 * @return true si une nourriture a été mangée
 */
bool Food::eatIfFood(unsigned int x, unsigned int y, GameParameters* param) {
    for (int i = 0; i < number; i++) {
        if (positionList[i]->x == x && positionList[i]->y == y) {
            initPosition(positionList[i], param, i, false);
            return true;
        }
    }
    return false;
}

/**
 * @brief Vérifie la présence de nourriture à une position donnée.
 * 
 * @param curIdx Index courant
 * @param x Coordonnée X
 * @param y Coordonnée Y
 * @param isInit Indique si on est en phase d’initialisation
 * @return true si nourriture présente
 */
bool Food::isFoodHere(unsigned int curIdx, unsigned int x, unsigned int y, bool isInit) {
    int born = isInit ? curIdx : number;
    for (int i = 0; i < born; i++) {
        if (i != curIdx && positionList[i]->x == x && positionList[i]->y == y) {
            return true;
        }
    }
    return false;
}

/**
 * @brief Dessine toutes les nourritures sur la fenêtre.
 * 
 * Chaque nourriture est représentée par un cercle dans la grille.
 * 
 * @param param Paramètres globaux du jeu
 * @param window Fenêtre de rendu SFML
 */
void Food::draw(GameParameters* param, sf::RenderWindow* window) {
    unsigned int nbLin = param->nbLin;
    unsigned int nbCol = param->nbCol;
    unsigned int width = param->widthWindow;
    unsigned int height = param->heightWindow;

    for (int i = 0; i < number; i++) {
        Position* pos = positionList[i];
        sf::CircleShape circle(width / nbCol / 2, 16);
        sf::Vector2f posCircle(pos->x * width / nbCol, pos->y * height / nbLin);

        circle.setPosition(posCircle);
        window->draw(circle);
    }
}

/**
 * @brief Réinitialise toutes les nourritures avec de nouvelles positions.
 * @param param Paramètres globaux
 */
void Food::init(GameParameters* param) {
    for (int i = 0; i < number; i++) {
        initPosition(positionList[i], param, i, true);
    }
}
