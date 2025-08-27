#include "../include/SnakeBit.hpp"

/**
 * @brief Constructeur d'un segment de serpent.
 * 
 * Crée un nouveau segment et l'insère dans la chaîne après le segment précédent.
 * Si c'est la tête (prec == nullptr), initialise à l'origine avec direction RIGHT.
 * Sinon, hérite de la position et direction du segment précédent.
 * 
 * @param prec Pointeur vers le segment précédent (plus proche de la tête)
 */
SnakeBit::SnakeBit(SnakeBit* prec) : next(nullptr), prec(prec) {
    if (prec) {
        // Ce n'est pas la tête : hérite du segment précédent
        dir = prec->dir;
        prec->next = this;  // Insertion dans la chaîne
        pos.x = prec->pos.x;
        pos.y = prec->pos.y;
    } else {
        // C'est la tête : position et direction par défaut
        pos.x = 0;
        pos.y = 0;
        dir = RIGHT;
    }
    nextDir = dir;  // Initialisation de la prochaine direction
}

/**
 * @brief Destructeur du segment.
 * 
 * Actuellement vide, mais peut être étendu pour la gestion
 * spécifique de ressources si nécessaire.
 */
SnakeBit::~SnakeBit() {
    // Destructeur vide pour l'instant
}

/**
 * @brief Met à jour le segment en copiant les données du précédent.
 * 
 * Utilisé pour tous les segments du corps (pas la tête).
 * Chaque segment "suit" le segment qui le précède en copiant
 * sa direction et sa position précédente.
 */
void SnakeBit::update() {
    this->dir = prec->dir;
    this->pos.x = prec->pos.x;
    this->pos.y = prec->pos.y;
}

/**
 * @brief Déplace le segment selon sa direction.
 * 
 * Applique d'abord nextDir à dir (pour gérer les changements
 * de direction), puis déplace la position selon la direction.
 * Cette méthode est principalement utilisée par la tête.
 */
void SnakeBit::move() {
    dir = nextDir;  // Application du changement de direction
    
    switch (dir) {
        case STOP:
            // Aucun mouvement
            break;
        case UP:
            this->pos.y = this->pos.y - 1;
            break;
        case DOWN:
            this->pos.y = this->pos.y + 1;
            break;
        case LEFT:
            this->pos.x = this->pos.x - 1;
            break;
        case RIGHT:
            this->pos.x = this->pos.x + 1;
            break;
        default:
            break;
    }
}

/**
 * @brief Change la direction du segment.
 * 
 * Vérifie que le changement de direction est valide en empêchant
 * les demi-tours (ex: impossible de passer de UP à DOWN directement).
 * Met à jour nextDir si le changement est autorisé.
 * 
 * @param newDir Nouvelle direction souhaitée
 */
void SnakeBit::changeDirection(SnakeDirection newDir) {
    switch (newDir) {
        case STOP:
            return;  // Pas de changement pour STOP
        case UP:
            if (dir == DOWN) return;  // Demi-tour interdit
            break;
        case DOWN:
            if (dir == UP) return;    // Demi-tour interdit
            break;
        case LEFT:
            if (dir == RIGHT) return; // Demi-tour interdit
            break;
        case RIGHT:
            if (dir == LEFT) return;  // Demi-tour interdit
            break;
        default:
            break;
    }
    
    this->nextDir = newDir;  // Changement autorisé
}

/**
 * @brief Dessine le segment dans la fenêtre.
 * 
 * Calcule la taille et position du rectangle en fonction
 * des paramètres de la grille et affiche un carré blanc
 * représentant le segment.
 * 
 * @param param Paramètres du jeu (dimensions fenêtre/grille)
 * @param window Fenêtre SFML où effectuer le rendu
 */
void SnakeBit::draw(GameParameters* param, sf::RenderWindow* window) {
    unsigned int nbLin = param->nbLin;
    unsigned int nbCol = param->nbCol;
    unsigned int width = param->widthWindow;
    unsigned int height = param->heightWindow;

    // Calcul de la taille d'une case de la grille
    sf::Vector2f sizeSquare(width / nbCol, height / nbLin);
    sf::RectangleShape square(sizeSquare);
    
    // Configuration visuelle du segment
    sf::Color color(sf::Color::White);
    sf::Vector2f posSquare(pos.x * width / nbCol, pos.y * height / nbLin);
    
    square.setFillColor(color);
    square.setPosition(posSquare);
    window->draw(square);
}