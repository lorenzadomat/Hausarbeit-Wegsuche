#ifndef SEARCHALGORITHMS_H
#define SEARCHALGORITHMS_H

#include <vector>
#include <string>
#include <queue>
#include <tuple>
#include <cmath>
#include <algorithm>
#include "config.h"
#include "Utils/Timer.cpp"
#include "Utils/Console.h"
#include "Maze.h"

class Search_Algorithms
{
private:
    float duration;
    int curEndX;
    int curEndY;
public:
	Search_Algorithms(){};
	virtual vector<tuple<Tile, Tile>> findPath(Maze) = 0;
    double distanceToPoint(int startY, int startX, int pEndY, int pEndX);
    bool sortByDistance(Tile* i, Tile* j);
    void setDuration(float pDuration){duration = pDuration;}
    float getDuration(){return duration;}
};

#endif