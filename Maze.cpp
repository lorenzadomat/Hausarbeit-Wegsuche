#ifndef HAUSARBEITWEGSUCHE_MAZE_HPP
#define HAUSARBEITWEGSUCHE_MAZE_HPP

#include "Maze.h"
#include "Tile.cpp"
#include <vector>
#include <stack>

Maze::Maze(int maze, int pStartX, int pStartY, int pEndX, int pEndY, int pColumns, int pRows) {
    startX = pStartX;
    startY = pStartY;
    endX = pEndX;
    endY = pEndY;
    columns = pColumns;
    rows = pRows;

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
    for(int i = 0; i < tiles.size(); i++){
        for(int j = 0; j < tiles[i].size(); j++){
            tiles[i][j].setVisited(false);
        }
    }
}

void Maze::exampleMaze1(){
    //TODO Leave out * tileSize
    tiles.insert(tiles.end(), vector<Tile>{
        Tile(0 * tileSize , 0 * tileSize , false, false, false, false),
        Tile(1 * tileSize , 0 * tileSize , false, true, true, false),
        Tile(2 * tileSize , 0 * tileSize , false, false, false, true),
        Tile(3 * tileSize , 0 * tileSize , false, true, true, false),
        Tile(4 * tileSize , 0 * tileSize , false, false, false, true)
    });
    tiles.insert(tiles.end(), vector<Tile>{
            Tile(0 * tileSize , 1 * tileSize , false, true, false, false),
            Tile(1 * tileSize , 1 * tileSize , true, false, true, true),
            Tile(2 * tileSize , 1 * tileSize , false, true, true, false),
            Tile(3 * tileSize , 1 * tileSize , true, true, false, true),
            Tile(4 * tileSize , 1 * tileSize , false, false, false, true)
    });
    tiles.insert(tiles.end(), vector<Tile>{
            Tile(0 * tileSize , 2 * tileSize , false, false, true, false),
            Tile(1 * tileSize , 2 * tileSize , true, true, true, false),
            Tile(2 * tileSize , 2 * tileSize , true, true, true, true),
            Tile(3 * tileSize , 2 * tileSize , false, true, false, true),
            Tile(4 * tileSize , 2 * tileSize , false, false, true, true)
    });
    tiles.insert(tiles.end(), vector<Tile>{
            Tile(0 * tileSize , 3 * tileSize , true, true, false, false),
            Tile(1 * tileSize , 3 * tileSize , true, true, true, true),
            Tile(2 * tileSize , 3 * tileSize , true, false, true, true),
            Tile(3 * tileSize , 3 * tileSize , false, true, true, false),
            Tile(4 * tileSize , 3 * tileSize , true, false, true, true)
    });
    tiles.insert(tiles.end(), vector<Tile>{
            Tile(0 * tileSize , 4 * tileSize , false, true, false, false),
            Tile(1 * tileSize , 4 * tileSize , true, false, false, true),
            Tile(2 * tileSize , 4 * tileSize , true, true, false, false),
            Tile(3 * tileSize , 4 * tileSize , true, false, false, true),
            Tile(4 * tileSize , 4 * tileSize , true, false, false, false)
    });

    setStart(startY, startX);
    setEnd(endY, endX);
}

void Maze::exampleMaze2() {
    //TODO
}
void Maze::genRandomMaze() {
    for(int y = 0; y < rows; y++){
        vector<Tile> row;
        for(int x = 0; x < columns; x++){
            row.insert(row.end(), Tile(x * tileSize , y * tileSize , false, false, false, false));
        }
        tiles.insert(tiles.end(), row);
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
    setStart(startY, startX);
    setEnd(endY, endX);
}

#endif
