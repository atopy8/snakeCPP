#include "../include/Snake.hpp"


Snake::Snake(){
    head = new SnakeBit(nullptr);
    tail = new SnakeBit(head);
    tail = new SnakeBit(tail);
    head->dir = STOP;
}

Snake::~Snake(){
    SnakeBit* currentBit = tail;
    SnakeBit* nextBit = tail;
    while (currentBit != head) {
        nextBit = currentBit->prec;
        currentBit->~SnakeBit();
        currentBit = nextBit;
    }
    head->~SnakeBit();
}

void Snake::draw(GameParameters* param, sf::RenderWindow* window) {

    SnakeBit* currentBit = tail;
    while (currentBit) {
        currentBit->draw(param, window);
        currentBit = currentBit->prec;
    }
}

void Snake::changeDirection(SnakeDirection dir) {
    
    head->changeDirection(dir);
}

void Snake::update() {
    if (head->dir != STOP){
        SnakeBit* currentBit = tail;
        while (currentBit != head) {
            currentBit->update();
            currentBit = currentBit->prec;
        }
        head->move();
    }
    
}

void Snake::eatIfFood(Food* food, GameParameters* param){
    if (food->eatIfFood(head->pos.x,head->pos.y, param)){
        tail = new SnakeBit(tail);
    }
}

bool Snake::stopIfDying(GameParameters* param){
    if (head->pos.x < 0 || head->pos.x >= param->nbCol || head->pos.y < 0 || head->pos.y >= param->nbLin){
        head->dir = STOP;
        return true;
    }
    SnakeBit* currentBit = tail;
    while (currentBit != head) {
        if (currentBit->pos.x == head->pos.x && currentBit->pos.y == head->pos.y){
            head->dir = STOP;
            return true;
        }
        currentBit = currentBit->prec;
    }
    return false;
}

bool Snake::isStopped(){
    return head->dir == STOP;
}

void Snake::init(){
    SnakeBit* cur;
    while(head->next->next != tail){
        cur = head->next;
        head->next = cur->next;
        head->next->prec = head;
        cur->~SnakeBit();
    }
    cur = head;
    while (cur){
        cur->pos.x = 0;
        cur->pos.y = 0;
        cur->dir = RIGHT;
        cur->nextDir = RIGHT;
        cur = cur->next;
    }
    
}