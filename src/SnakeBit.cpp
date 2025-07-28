#include "../include/SnakeBit.hpp"

SnakeBit::SnakeBit(SnakeBit* prec): 
    dir(next->dir), next(nullptr), prec(prec) {}

void SnakeBit::update() {
    this->dir       = next->dir;
    this->pos->x    = next->pos->x;
    this->pos->y    = next->pos->y;
}