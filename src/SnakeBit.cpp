#include "../include/SnakeBit.hpp"

SnakeBit::SnakeBit(SnakeBit* prec): 
    next(nullptr), prec(prec) {
        if (prec) {
            dir = prec->dir;
            prec->next = this;
            pos.x = prec->pos.x;
            pos.y = prec->pos.y;
        }else{
            pos.x = 0;
            pos.y = 0;
            dir = RIGHT;
        }
        nextDir = dir;
        
    }

SnakeBit::~SnakeBit(){

}

void SnakeBit::update() {
    this->dir       = prec->dir;
    this->pos.x    = prec->pos.x;
    this->pos.y    = prec->pos.y;
}

void SnakeBit::move(){
    dir = nextDir;
    switch (dir)
    {
    case STOP:
        break;
    case UP:
        this->pos.x    = this->pos.x;
        this->pos.y    = this->pos.y - 1;
        break;
    case DOWN:
        this->pos.x    = this->pos.x;
        this->pos.y    = this->pos.y + 1;
        break;
    case LEFT:
        this->pos.x    = this->pos.x - 1;
        this->pos.y    = this->pos.y;
        break;
    case RIGHT:
        this->pos.x    = this->pos.x + 1;
        this->pos.y    = this->pos.y;
        break;
    default:
        break;
    }
}

void SnakeBit::changeDirection(SnakeDirection newDir){
    switch (newDir)
    {
    case STOP:
        return;
        break;
    case UP:
        if (dir == DOWN){
            return;
        }
        break;
    case DOWN:
        if (dir == UP){
            return;
        }
        break;
    case LEFT:
        if (dir == RIGHT){
            return;
        }
        break;
    case RIGHT:
        if (dir == LEFT){
            return;
        }
        break;
    default:
        break;
    }
    this->nextDir = newDir;
}

void SnakeBit::draw(GameParameters* param, sf::RenderWindow* window) {
    unsigned int nbLin = param->nbLin;
    unsigned int nbCol = param->nbCol;
    unsigned int width = param->widthWindow;
    unsigned int height= param->heightWindow;

    sf::Vector2f sizeSquare(width / nbCol, height / nbLin);
    sf::RectangleShape square(sizeSquare);
    sf::Color color(sf::Color::White);
    sf::Vector2f posSquare(pos.x * width / nbCol, pos.y * height / nbLin);
    //sf::Vector2f posSquare(0, 0);
    square.setFillColor(color);
    square.setPosition(posSquare);
    window->draw(square);
}