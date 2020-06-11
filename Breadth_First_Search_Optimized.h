#ifndef BREADTH_OPTIMIZED_H
#define BREADTH_OPTIMIZED_H

#include "Search_Algorithms.h"

class Breadth_First_Search_Optimized: public Search_Algorithms
{
private:
public:
	Breadth_First_Search_Optimized();
	vector<tuple<Tile, Tile>> findPath(Maze);
};

#endif