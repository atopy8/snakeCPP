#include "../include/Snake.hpp"

Snake::Snake(){
    head = new SnakeBit(nullptr);
    tail = new SnakeBit(head);
    tail = new SnakeBit(tail);
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

void Snake::draw(sf::RenderWindow* window) {

    SnakeBit* currentBit = tail;
    while (currentBit) {
        currentBit->draw(window);
        currentBit = currentBit->prec;
    }
    currentBit->draw(window);
}

void Snake::changeDirection(SnakeDirection dir) {
    head->changeDirection(dir);
}

void Snake::update() {

    SnakeBit* currentBit = tail;
    while (currentBit != head) {
        currentBit->update();
        currentBit = currentBit->prec;
    }
    head->moveToward(head->dir);
}