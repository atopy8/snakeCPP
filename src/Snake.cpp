#include "../include/Snake.hpp"

/**
 * @brief Constructeur du serpent.
 * 
 * Crée un serpent initial composé d'une tête et de deux segments,
 * reliés en liste chaînée. Le serpent commence immobile.
 */
Snake::Snake() {
    head = new SnakeBit(nullptr);  // Création de la tête
    tail = new SnakeBit(head);     // Premier segment du corps
    tail = new SnakeBit(tail);     // Second segment du corps
    head->dir = STOP;              // Le serpent commence arrêté
}

/**
 * @brief Destructeur du serpent.
 * 
 * Parcourt la liste chaînée depuis la queue vers la tête
 * et libère la mémoire de chaque segment.
 */
Snake::~Snake() {
    SnakeBit* currentBit = tail;
    SnakeBit* nextBit = tail;
    
    // Libération de tous les segments sauf la tête
    while (currentBit != head) {
        nextBit = currentBit->prec;
        currentBit->~SnakeBit();
        currentBit = nextBit;
    }
    
    // Libération de la tête
    head->~SnakeBit();
}

/**
 * @brief Dessine le serpent dans la fenêtre.
 * 
 * Parcourt tous les segments depuis la queue vers la tête
 * et appelle la méthode draw de chaque SnakeBit.
 * 
 * @param param Paramètres du jeu pour les dimensions d'affichage
 * @param window Fenêtre SFML où effectuer le rendu
 */
void Snake::draw(GameParameters* param, sf::RenderWindow* window) {
    SnakeBit* currentBit = tail;
    
    while (currentBit) {
        currentBit->draw(param, window);
        currentBit = currentBit->prec;
    }
}

/**
 * @brief Change la direction du serpent.
 * 
 * Délègue le changement de direction à la tête du serpent,
 * qui gère les restrictions de mouvement (pas de demi-tour).
 * 
 * @param dir Nouvelle direction souhaitée
 */
void Snake::changeDirection(SnakeDirection dir) {
    head->changeDirection(dir);
}

/**
 * @brief Met à jour la position de tous les segments.
 * 
 * Si le serpent bouge, chaque segment suit la position
 * du segment précédent, puis la tête se déplace.
 */
void Snake::update() {
    if (head->dir != STOP) {
        SnakeBit* currentBit = tail;
        
        // Mise à jour de tous les segments (queue vers tête)
        while (currentBit != head) {
            currentBit->update();
            currentBit = currentBit->prec;
        }
        
        // Mouvement de la tête
        head->move();
    }
}

/**
 * @brief Vérifie si le serpent mange une nourriture.
 * 
 * Teste si la position de la tête correspond à une nourriture.
 * Si oui, fait grandir le serpent d'un segment à la queue.
 * 
 * @param food Gestionnaire des nourritures
 * @param param Paramètres du jeu
 */
void Snake::eatIfFood(Food* food, GameParameters* param) {
    if (food->eatIfFood(head->pos.x, head->pos.y, param)) {
        // Ajout d'un nouveau segment à la queue
        tail = new SnakeBit(tail);
    }
}

/**
 * @brief Vérifie les conditions de mort du serpent.
 * 
 * Teste deux conditions fatales :
 * - Collision avec les bords de la grille
 * - Collision avec le corps du serpent
 * 
 * @param param Paramètres du jeu (dimensions de la grille)
 * @return true si le serpent est mort, false sinon
 */
bool Snake::stopIfDying(GameParameters* param) {
    // Vérification des collisions avec les bords
    if (head->pos.x < 0 || head->pos.x >= param->nbCol || 
        head->pos.y < 0 || head->pos.y >= param->nbLin) {
        head->dir = STOP;
        return true;
    }
    
    // Vérification des collisions avec le corps
    SnakeBit* currentBit = tail;
    while (currentBit != head) {
        if (currentBit->pos.x == head->pos.x && 
            currentBit->pos.y == head->pos.y) {
            head->dir = STOP;
            return true;
        }
        currentBit = currentBit->prec;
    }
    
    return false;
}

/**
 * @brief Indique si le serpent est arrêté.
 * 
 * @return true si la direction est STOP, false sinon
 */
bool Snake::isStopped() {
    return head->dir == STOP;
}

/**
 * @brief Réinitialise le serpent pour une nouvelle partie.
 * 
 * Réduit le serpent à sa taille minimale et le repositionne
 * à l'origine avec une direction par défaut (RIGHT).
 */
void Snake::init() {
    SnakeBit* cur;
    
    // Suppression des segments excédentaires
    while (head->next->next != tail) {
        cur = head->next;
        head->next = cur->next;
        head->next->prec = head;
        cur->~SnakeBit();
    }
    
    // Réinitialisation des positions et directions
    cur = head;
    while (cur) {
        cur->pos.x = 0;
        cur->pos.y = 0;
        cur->dir = RIGHT;
        cur->nextDir = RIGHT;
        cur = cur->next;
    }
}