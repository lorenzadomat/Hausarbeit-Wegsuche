#ifndef BREADTH_H
#define BREADTH_H

#include "Search_Algorithms.h"

class Breadth_First_Search: public Search_Algorithms
{
private:

public:
	Breadth_First_Search();
	vector<tuple<Tile, Tile>> findPath(Maze);
};

#endif