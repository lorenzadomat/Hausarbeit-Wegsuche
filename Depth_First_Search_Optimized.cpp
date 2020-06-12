#include "Depth_First_Search_Optimized.h"

Depth_First_Search_Optimized::Depth_First_Search_Optimized()
{
}

/**
 * Only to sort a max of 4 tiles
 */
vector<Tile*> Depth_First_Search_Optimized::sortByDistance(vector<Tile*> tiles, Tile* end){
    vector<Tile*> sorted;
    float bufDist;
    int index;
    float distance;

    while(tiles.size() > 0){
        bufDist = INT_MAX;
        index = -1;
        for (int i = 0; i < tiles.size(); i++) {
            distance = distanceToPoint(tiles.at(i)->getY(), tiles.at(i)->getX(), end->getY(), end->getX());
            if (distance < bufDist) {
                index = i;
                bufDist = distance;
            }
        }
        sorted.insert(sorted.end(), tiles[index]);
        tiles.erase(tiles.begin() + index);
    }
    return sorted;
}

/*
	recursive depth-frist-search algorithm
*/
void Depth_First_Search_Optimized::dfs(Maze* maze, Tile * tile)
{
    if (tile == maze->getEnd()) {
        finished = true; //stop search after end has been found
    }
    if (!tile->isVisited()) {
        tile->setVisited(true);
        vector<Tile*> neighbours = maze->getUnvisitedAccessibleNeighbours(tile->getY() / tileSize, tile->getX() / tileSize);
        neighbours = sortByDistance(neighbours, maze->getEnd());
        for (int i = 0; i < neighbours.size(); i++) {
            if (!finished) {
                finalPath.insert(finalPath.end(), make_tuple(*tile, *neighbours.at(i)));
                dfs(maze, neighbours.at(i));
            }
        }
    }
}

vector<tuple<Tile, Tile>> Depth_First_Search_Optimized::findPath(Maze maze)
{
    maze.reset();
    Timer timer;
    //Start Timer
    timer.start();

    //Start Algorithm
    dfs(&maze,maze.getStart());
    //End Algorithm

    //End Timer
    timer.stop();
    printTableRow("Depth_First_Search_Opt", timer.getDuration(), maze.getNumberOfCalls());
    return finalPath;
}

