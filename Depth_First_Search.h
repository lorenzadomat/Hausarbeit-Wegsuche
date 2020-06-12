#ifndef DEPTH_H
#define DEPTH_H

#include "Search_Algorithms.h"

class Depth_First_Search: public Search_Algorithms
{
private:
    vector<tuple<Tile, Tile>> finalPath;
    bool finished = false;
public:
    Depth_First_Search();
    vector<tuple<Tile, Tile>> findPath(Maze);
    void dfs(Maze*, Tile*);
};

#endif