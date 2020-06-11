#include "Depth_First_Search_Optimized.h"

Depth_First_Search_Optimized::Depth_First_Search_Optimized()
{
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
        sort(neighbours.begin(), neighbours.end(), sortByDistance)
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
    printTableRow("Tiefensuche", timer.getDuration(), maze.getNumberOfCalls());
    this->setDuration(timer.getDuration());
    return finalPath;
}

