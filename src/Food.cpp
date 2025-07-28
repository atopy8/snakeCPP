#include <stdlib.h>
#include "../include/Food.hpp"

Food::Food(unsigned int number)
    : number(number) {
        positionList = new Position*[number];
    }

bool Food::eatIfFood(unsigned int x, unsigned int y){
    for (int i = 0; i<number; i++){
        if (positionList[i]->x == x && positionList[i]->y == y){
            positionList[i]->x = rand() % 20;
            positionList[i]->y = rand() % 80;
            while (isFoodHere(positionList[i]->x, positionList[i]->y)){
                positionList[i]->x = rand() % 20;
                positionList[i]->y = rand() % 80;
            }
            return true;
        }
    }
    return false;
}

bool Food::isFoodHere(unsigned int x, unsigned int y) {
    for (int i = 0; i<number; i++){
        if (positionList[i]->x == x && positionList[i]->y == y){
            return true;
        }
    }
    return false;
}