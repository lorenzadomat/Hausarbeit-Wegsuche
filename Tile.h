#ifndef TILE_H
#define TILE_H

class Tile
{
private:
    int x;
    int y;
    bool top;
    bool right;
    bool bottom;
    bool left;
    bool visited;
    int distance;
    Tile* predecessor;
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
    int getDistance() { return distance; }
    Tile* getPredecessor() { return predecessor; }
    glm::vec4 getColor(){return color;}
    bool isVisited(){ return visited;}
    void setDistance(int pDistance);
    void setPredecessor(Tile* pPred);
    void setColor(glm::vec4 pColor){color = pColor;}
    void setVisited(bool value){ visited = value;}
    void setX(int pX){x = pX;}
    void setY(int pY){y = pY;}
    void setTop(bool value){top = value;}
    void setRight(bool value){right = value;}
    void setBottom(bool value){bottom = value;}
    void setLeft(bool value){left = value;}
    void setValues(int pX, int pY, bool pTop, bool pRight, bool pBottom, bool pLeft);
    friend ostream& operator<< (ostream &ostr, const Tile& t){
        ostr << "x = " << static_cast<int>(t.x) / tileSize << "; y = " << static_cast<int>(t.y) / tileSize<< " | Top: " << static_cast<bool>(t.top) << " | Right: " << static_cast<bool>(t.right) << " | Bottom: " << static_cast<bool>(t.bottom) << " | Left: " << static_cast<bool>(t.left) << "\n";
        return ostr;
    }

};

#endif
