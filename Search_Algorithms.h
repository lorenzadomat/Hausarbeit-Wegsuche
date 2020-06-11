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
public:
	Search_Algorithms() {}
	virtual vector<tuple<Tile, Tile>> findPath(Maze) = 0;
    double distanceToPoint(int startY, int startX, int pEndY, int pEndX) {
        return sqrt(pow(pEndX - startX, 2) + pow(pEndY - startY, 2));
    }
};

#endif