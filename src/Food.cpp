#include <stdlib.h>
#include "../include/Food.hpp"

Food::Food(unsigned int number, GameParameters* param)
    : number(number) {
        positionList = new Position*[number];
        for (int i = 0; i<number; i++){
            positionList[i] = new Position;
            positionList[i]->x = rand() % param->nbCol - 1;
            positionList[i]->y = rand() % param->nbLin - 1;
            while (isFoodHereInit(i, positionList[i]->x, positionList[i]->y)){
                positionList[i]->x = rand() % param->nbCol - 1;
                positionList[i]->y = rand() % param->nbLin - 1;
            }
        }
    }

Food::~Food(){
    delete[] positionList;

}

bool Food::eatIfFood(unsigned int x, unsigned int y, GameParameters* param){
    for (int i = 0; i<number; i++){
        if (positionList[i]->x == x && positionList[i]->y == y){
            positionList[i]->x = rand() % param->nbCol - 1;
            positionList[i]->y = rand() % param->nbLin - 1;
            while (isFoodHere(i,positionList[i]->x, positionList[i]->y)){
                positionList[i]->x = rand() % param->nbCol - 1;
                positionList[i]->y = rand() % param->nbLin - 1;
            }
            return true;
        }
    }
    return false;
}

bool Food::isFoodHereInit(unsigned int curIdx, unsigned int x, unsigned int y) {
    for (int i = 0; i<curIdx; i++){
        if (positionList[i]->x == x && positionList[i]->y == y){
            return true;
        }
    }
    return false;
}

bool Food::isFoodHere(unsigned int curIdx, unsigned int x, unsigned int y) {
    for (int i = 0; i<number; i++){
        if (i!=curIdx && positionList[i]->x == x && positionList[i]->y == y){
            return true;
        }
    }
    return false;
}

void Food::draw(GameParameters* param, sf::RenderWindow* window){
    unsigned int nbLin = param->nbLin;
    unsigned int nbCol = param->nbCol;
    unsigned int width = param->widthWindow;
    unsigned int height= param->heightWindow;

    for (int i = 0; i<number; i++){
        Position* pos = positionList[i];
        sf::CircleShape circle(width / nbCol / 2,16);
        sf::Vector2f posCircle(pos->x * width / nbCol, pos->y * height / nbLin);

        circle.setPosition(posCircle);
        window->draw(circle);
    }
    
}