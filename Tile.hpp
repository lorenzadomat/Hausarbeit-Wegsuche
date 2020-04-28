#include "config.hpp"
#include <iostream>
#include "libxd-0.3.2-Darwin/include/glm/glm.hpp"
#ifndef HAUSARBEITWEGSUCHE_TILE_HPP
#define HAUSARBEITWEGSUCHE_TILE_HPP

class Tile
{
private:
    int x;
    int y;
    bool top;
    bool right;
    bool bottom;
    bool left;
    bool visited = false;
    glm::vec4 color = glm::vec4(1, 1, 1, 0);
public:
    Tile();
    Tile(int pX, int pY, bool pTop, bool pRight, bool pBottom, bool pLeft);
    bool getTop(){ return top;}
    bool getRight(){ return right;}
    bool getBottom(){ return bottom;}
    bool getLeft(){ return left;}
    int getX(){return x;}
    int getY(){return y;}
    glm::vec4 getColor(){return color;}
    bool isVisited(){ return visited;}
    void setColor(glm::vec4 pColor){color = pColor;}
    void setVisited(bool value){ visited = value;}
    void setX(int pX){x = pX;}
    void setY(int pY){y = pY;}
    void setTop(bool value){top = value;}
    void setRight(bool value){right = value;}
    void setBottom(bool value){bottom = value;}
    void setLeft(bool value){left = value;}
    void setValues(int pX, int pY, bool pTop, bool pRight, bool pBottom, bool pLeft);
    void print();

};
Tile::Tile() {
}
Tile::Tile(int pX, int pY ,bool pTop, bool pRight, bool pBottom, bool pLeft) {
    x = pX;
    y = pY;
    top = pTop;
    right = pRight;
    bottom = pBottom;
    left = pLeft;
}
void Tile::setValues(int pX, int pY, bool pTop, bool pRight, bool pBottom, bool pLeft) {
    x = pX;
    y = pY;
    top = pTop;
    right = pRight;
    bottom = pBottom;
    left = pLeft;
}

void Tile::print() {
    std::cout << "x = " << x / tileSize << "; y = " << y / tileSize<< " | Top: " << top << " | Right: " << right << " | Bottom: " << bottom << " | Left: " << left << "\n";
}

#endif
