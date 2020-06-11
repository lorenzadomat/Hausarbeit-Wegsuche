#ifndef DEPTH_OPTIMIZED_H
#define DEPTH_OPTIMIZED_H

class Depth_First_Search_Optimized: public Search_Algorithms
{
private:
    vector<tuple<Tile, Tile> > finalPath;
    int curEndX;
    int curEndY;
    bool finished;
public:
    Depth_First_Search_Optimized();
    vector<tuple<Tile, Tile>> findPath(Maze);
    bool sortByDistance(Tile *i, Tile* j);
    void dfs(Maze*, Tile*);
    void setEnd(int pY, int pX){curEndX = pX; curEndY = pY;}
};
#endif
