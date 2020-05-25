#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "Search_Algorithms.h"

class Dijkstra_Algorithm: public Search_Algorithms
{
private:

public:
	Dijkstra_Algorithm(); 
	vector<tuple<Tile, Tile>> findPath(Maze);
};

#endif