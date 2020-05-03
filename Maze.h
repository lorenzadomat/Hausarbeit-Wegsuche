#ifndef MAZE_H
#define MAZE_H

#include "config.h"
#include "Tile.h"
#include <vector>

class Maze
{
private:
    vector<vector<Tile>> tiles;
    int startX;
    int startY;
    int endX;
    int endY;
    int numberOfCalls;
    int columns;
    int rows;
public:
    Maze(){};
    Maze(int maze, int pStartX, int pStartY, int pEndX, int pEndY, int pColumns, int pRows);
    Tile* getTile(int pY, int pX);
    Tile* getStart();
    Tile* getEnd();
    int getRows(){return rows;}
    int getColumns(){return columns;}
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

#endif
