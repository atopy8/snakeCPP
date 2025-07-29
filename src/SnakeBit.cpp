#include "../include/SnakeBit.hpp"

SnakeBit::SnakeBit(SnakeBit* prec): 
    next(nullptr), prec(prec) {
        pos = new Position;
        if (prec) {
            dir = prec->dir;
            prec->next = this;
            pos->x = prec->pos->x;
            pos->y = prec->pos->y;
        }else{
            pos->x = 0;
            pos->y = 0;
            dir = RIGHT;
        }
        
    }

SnakeBit::~SnakeBit(){

}

void SnakeBit::update() {
    this->dir       = prec->dir;
    this->pos->x    = prec->pos->x;
    this->pos->y    = prec->pos->y;
}

void SnakeBit::moveToward(SnakeDirection dir){
    switch (dir)
    {
    case STOP:
        break;
    case UP:
        this->pos->x    = this->pos->x;
        this->pos->y    = this->pos->y - 1;
        break;
    case DOWN:
        this->pos->x    = this->pos->x;
        this->pos->y    = this->pos->y + 1;
        break;
    case LEFT:
        this->pos->x    = this->pos->x - 1;
        this->pos->y    = this->pos->y;
        break;
    case RIGHT:
        this->pos->x    = this->pos->x + 1;
        this->pos->y    = this->pos->y;
        break;
    default:
        break;
    }
}

void SnakeBit::changeDirection(SnakeDirection newDir){
    this->dir = newDir;
}

void SnakeBit::draw(sf::RenderWindow* window) {
    unsigned int nbLin = 45;
    unsigned int nbCol = 80;
    unsigned int width = 1920;
    unsigned int height= 1080;
    sf::Vector2f sizeSquare(width / nbCol, height / nbLin);
    sf::RectangleShape square(sizeSquare);
    sf::Color color(sf::Color::White);
    //sf::Vector2f posSquare(pos->x, pos->y);
    sf::Vector2f posSquare(0, 0);
    square.setFillColor(color);
    square.setPosition(posSquare);
    window->draw(square);
}