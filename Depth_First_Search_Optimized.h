#ifndef DEPTH_OPTIMIZED_H
#define DEPTH_OPTIMIZED_H

class Depth_First_Search_Optimized: public Search_Algorithms
{
private:
    vector<tuple<Tile, Tile> > finalPath;
    bool finished;
public:
    Depth_First_Search_Optimized();
    vector<tuple<Tile, Tile>> findPath(Maze);
    void dfs(Maze*, Tile*);
};
#endif
