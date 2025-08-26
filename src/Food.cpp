#include <stdlib.h>
#include "../include/Food.hpp"


void Food::initPosition(Position* position, GameParameters* param, int i, bool isInit){
    position->x = rand() % param->nbCol - 1;
    position->y = rand() % param->nbLin - 1;
    while (isFoodHere(i, position->x, position->y, isInit)){
        position->x = rand() % param->nbCol - 1;
        position->y = rand() % param->nbLin - 1;
    }
}

Food::Food(unsigned int number, GameParameters* param)
    : number(number) {
        positionList = new Position*[number];
        for (int i = 0; i<number; i++){
            positionList[i] = new Position;
            initPosition(positionList[i], param, i, true);
        }
    }

Food::~Food(){
    delete[] positionList;

}

bool Food::eatIfFood(unsigned int x, unsigned int y, GameParameters* param){
    for (int i = 0; i<number; i++){
        if (positionList[i]->x == x && positionList[i]->y == y){
            initPosition(positionList[i], param, i, false);
            return true;
        }
    }
    return false;
}

bool Food::isFoodHere(unsigned int curIdx, unsigned int x, unsigned int y, bool isInit) {
    int born = isInit ? curIdx : number;
    for (int i = 0; i<born; i++){
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

void Food::init(GameParameters* param){
    for (int i = 0; i<number; i++){
        initPosition(positionList[i], param, i, true);
    }
}