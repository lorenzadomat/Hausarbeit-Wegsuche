#ifndef HAUSARBEITWEGSUCHE_TILE_HPP
#define HAUSARBEITWEGSUCHE_TILE_HPP

#include "config.h"
#include "Tile.h"

Tile::Tile() {
}
Tile::Tile(int pX, int pY ,bool pTop, bool pRight, bool pBottom, bool pLeft) {
    x = pX;
    y = pY;
    top = pTop;
    right = pRight;
    bottom = pBottom;
    left = pLeft;
    visited = false;
}
void Tile::setValues(int pX, int pY, bool pTop, bool pRight, bool pBottom, bool pLeft) {
    x = pX;
    y = pY;
    top = pTop;
    right = pRight;
    bottom = pBottom;
    left = pLeft;
}

void Tile::setDistance(int pDistance) {
    distance = pDistance;
}

void Tile::setPredecessor(Tile* pPred) {
    predecessor = pPred;
}

#endif
