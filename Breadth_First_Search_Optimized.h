#ifndef BREADTH_OPTIMIZED_H
#define BREADTH_OPTIMIZED_H

#include "Search_Algorithms.h"

class Breadth_First_Search_Optimized: public Search_Algorithms
{
private:
	int curEndX = 0;
	int curEndY = 0;
public:
	Breadth_First_Search_Optimized();
	vector<tuple<Tile, Tile>> findPath(Maze);
	double distanceToPoint(int, int, int, int);
	bool sortByDistanceToEnd(Tile*, Tile*);
};

#endif