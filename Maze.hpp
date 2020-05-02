#include "config.hpp"
#include "Tile.hpp"
#include <vector>
#include <stack>
#ifndef HAUSARBEITWEGSUCHE_MAZE_HPP
#define HAUSARBEITWEGSUCHE_MAZE_HPP

using namespace std;

class Maze
{
private:
    Tile tiles[rows][columns]; //TODO Überlegen als Datentyp vector zu benutzten
    int startX;
    int startY;
    int endX;
    int endY;
    int numberOfCalls;
public:
    Maze(){};
    Maze(int maze, int pStartX, int pStartY, int pEndX, int pEndY);
    Tile* getTile(int pY, int pX);
    Tile* getStart();
    Tile* getEnd();
    Tile* getTopNeighbour(int pY, int pX);
    Tile* getRightNeighbour(int pY, int pX);
    Tile* getBottomNeighbour(int pY, int pX);
    Tile* getLeftNeighbour(int pY, int pX);
    vector<Tile*> getUnvisitedNeighbours(int pY, int pX);
    vector<Tile*> getUnvisitedAccessibleNeighbours(int pY, int pX);
    int getNumberOfCalls(){return numberOfCalls;}
    void exampleMaze1();
    void exampleMaze2();
    void genRandomMaze();
    void reset();
    void setStart(int pY, int pX);
    void setEnd(int pY, int pX);
};

Maze::Maze(int maze, int pStartX, int pStartY, int pEndX, int pEndY) {
    setStart(pStartY, pStartX);
    setEnd(pEndY, pEndX);
    if(maze == 0) {
        exampleMaze1();
    }else if(maze == 1){
        exampleMaze2();
    }else if(maze == 2){
        genRandomMaze();
    }

}

Tile* Maze::getTile(int pY, int pX) {
    if(pX >= 0 && pX < rows && pY >= 0 && pY < columns){
        numberOfCalls+=1;
        return &tiles[pY][pX];
    }
    return nullptr;
}
Tile* Maze::getStart() {
    numberOfCalls+=1;
    return &tiles[startY][startX];
}
Tile* Maze::getEnd() {
    numberOfCalls+=1;
    return &tiles[endY][endX];
}

Tile* Maze::getTopNeighbour(int pY, int pX){
    if(pX >= 0 && pX < columns && pY > 0 && pY < rows){
        numberOfCalls+=1;
        return &tiles[pY - 1][pX];
    }
    return nullptr;
}
Tile* Maze::getRightNeighbour(int pY, int pX){
    if(pX >= 0 && pX < columns - 1 && pY >= 0 && pY < rows){
        numberOfCalls+=1;
        return &tiles[pY][pX + 1];
    }
    return nullptr;
}
Tile* Maze::getBottomNeighbour(int pY, int pX){
    if(pX >= 0 && pX < columns && pY >= 0 && pY < rows - 1){
        numberOfCalls+=1;
        return &tiles[pY + 1][pX];
    }
    return nullptr;
}
Tile* Maze::getLeftNeighbour(int pY, int pX){
    if(pX > 0 && pX < columns && pY >= 0 && pY < rows){
        numberOfCalls+=1;
        return &tiles[pY][pX - 1];
    }
    return nullptr;
}

void Maze::setStart(int pY, int pX) {
    startX = pX;
    startY = pY;
    tiles[pY][pX].setColor(glm::vec4(0.0, 1.0, 0.0, 1.0));
}

void Maze::setEnd(int pY, int pX) {
    endX = pX;
    endY = pY;
    tiles[pY][pX].setColor(glm::vec4(1.0, 0.0, 0.0, 1.0));
}

vector<Tile*> Maze::getUnvisitedAccessibleNeighbours(int pY, int pX) {
    vector<Tile*> list;
    Tile* neighbour = getTopNeighbour(pY,pX);
    if(neighbour && !neighbour->isVisited() && neighbour->getBottom()){
        list.insert(list.end(), neighbour);
    }
    neighbour = getRightNeighbour(pY,pX);
    if(neighbour && !neighbour->isVisited() && neighbour->getLeft()){
        list.insert(list.end(), neighbour);
    }
    neighbour = getBottomNeighbour(pY,pX);
    if(neighbour && !neighbour->isVisited() && neighbour->getTop()){
        list.insert(list.end(), neighbour);
    }
    neighbour = getLeftNeighbour(pY,pX);
    if(neighbour && !neighbour->isVisited() && neighbour->getRight()){
        list.insert(list.end(), neighbour);
    }
    return list;
}

vector<Tile*> Maze::getUnvisitedNeighbours(int pY, int pX) {
    vector<Tile*> list;
    Tile* neighbour = getTopNeighbour(pY,pX);
    if(neighbour && !neighbour->isVisited()){
        list.insert(list.end(), neighbour);
    }
    neighbour = getRightNeighbour(pY,pX);
    if(neighbour && !neighbour->isVisited()){
        list.insert(list.end(), neighbour);
    }
    neighbour = getBottomNeighbour(pY,pX);
    if(neighbour && !neighbour->isVisited()){
        list.insert(list.end(), neighbour);
    }
    neighbour = getLeftNeighbour(pY,pX);
    if(neighbour && !neighbour->isVisited()){
        list.insert(list.end(), neighbour);
    }
    return list;
}



/**
 * Resets the Maze + all Tiles so that a new Algorithm can start
 */
void Maze::reset() {
    numberOfCalls = 0;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            tiles[i][j].setVisited(false);
        }
    }
}

void Maze::exampleMaze1(){
    //TODO Leave out * tileSize
    setStart(0, 3);
    setEnd(4, 2);
    tiles[0][0].setValues(0 * tileSize , 0 * tileSize , false, false, false, false);
    tiles[0][1].setValues(1 * tileSize , 0 * tileSize , false, true, true, false);
    tiles[0][2].setValues(2 * tileSize , 0 * tileSize , false, false, false, true);
    tiles[0][3].setValues(3 * tileSize , 0 * tileSize , false, true, true, false);
    tiles[0][4].setValues(4 * tileSize , 0 * tileSize , false, false, false, true);
    tiles[1][0].setValues(0 * tileSize , 1 * tileSize , false, true, false, false);
    tiles[1][1].setValues(1 * tileSize , 1 * tileSize , true, false, true, true);
    tiles[1][2].setValues(2 * tileSize , 1 * tileSize , false, true, true, false);
    tiles[1][3].setValues(3 * tileSize , 1 * tileSize , true, true, false, true);
    tiles[1][4].setValues(4 * tileSize , 1 * tileSize , false, false, false, true);
    tiles[2][0].setValues(0 * tileSize , 2 * tileSize , false, false, true, false);
    tiles[2][1].setValues(1 * tileSize , 2 * tileSize , true, true, true, false);
    tiles[2][2].setValues(2 * tileSize , 2 * tileSize , true, true, true, true);
    tiles[2][3].setValues(3 * tileSize , 2 * tileSize , false, true, false, true);
    tiles[2][4].setValues(4 * tileSize , 2 * tileSize , false, false, true, true);
    tiles[3][0].setValues(0 * tileSize , 3 * tileSize , true, true, false, false);
    tiles[3][1].setValues(1 * tileSize , 3 * tileSize , true, true, true, true);
    tiles[3][2].setValues(2 * tileSize , 3 * tileSize , true, false, true, true);
    tiles[3][3].setValues(3 * tileSize , 3 * tileSize , false, true, true, false);
    tiles[3][4].setValues(4 * tileSize , 3 * tileSize , true, false, true, true);
    tiles[4][0].setValues(0 * tileSize , 4 * tileSize , false, true, false, false);
    tiles[4][1].setValues(1 * tileSize , 4 * tileSize , true, false, false, true);
    tiles[4][2].setValues(2 * tileSize , 4 * tileSize , true, true, false, false);
    tiles[4][3].setValues(3 * tileSize , 4 * tileSize , true, false, false, true);
    tiles[4][4].setValues(4 * tileSize , 4 * tileSize , true, false, false, false);
}

void Maze::exampleMaze2() {
    //TODO
}
void Maze::genRandomMaze() {
    for(int y = 0; y < rows; y++){
        for(int x = 0; x < columns; x++){
            tiles[y][x].setValues(x * tileSize , y * tileSize , false, false, false, false);
        }
    }

    stack<Tile*> stack;
    tiles[startY][startX].setVisited(true);
    stack.push(&tiles[startY][startX]);
    Tile* curCell;
    while(stack.size() > 0){
        curCell = stack.top();
        vector<Tile *> neighbours = getUnvisitedNeighbours(curCell->getY() / tileSize, curCell->getX() / tileSize);
        stack.pop();
        if(neighbours.size() > 0){
            stack.push(curCell);
            int random = rand() % neighbours.size();
            if(getTopNeighbour(curCell->getY() / tileSize, curCell->getX() / tileSize) == neighbours[random]){
                curCell->setTop(true);
                neighbours[random]->setBottom(true);
            }else if(getRightNeighbour(curCell->getY() / tileSize, curCell->getX() / tileSize) == neighbours[random]){
                curCell->setRight(true);
                neighbours[random]->setLeft(true);
            }else if(getBottomNeighbour(curCell->getY() / tileSize, curCell->getX() / tileSize) == neighbours[random]){
                curCell->setBottom(true);
                neighbours[random]->setTop(true);
            }else if(getLeftNeighbour(curCell->getY() / tileSize, curCell->getX() / tileSize) == neighbours[random]){
                curCell->setLeft(true);
                neighbours[random]->setRight(true);
            }
            neighbours[random]->setVisited(true);
            stack.push(neighbours[random]);
        }
    }
    /**
     * Optional Part
     */
    for(int y = 1; y < rows * 5; y++){
        int randY = rand() % (rows - 2) + 1;
        int randX = rand() % (columns - 2) + 1;

        tiles[randY][randX].setTop(true);
        getTopNeighbour(randY, randX)->setBottom(true);
        tiles[randY][randX].setRight(true);
        getRightNeighbour(randY, randX)->setLeft(true);
        tiles[randY][randX].setBottom(true);
        getBottomNeighbour(randY, randX)->setTop(true);
        tiles[randY][randX].setLeft(true);
        getLeftNeighbour(randY, randX)->setRight(true);
    }
}

#endif
