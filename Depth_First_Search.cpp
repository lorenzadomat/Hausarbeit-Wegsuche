#include "Depth_First_Search.h"

Depth_First_Search::Depth_First_Search()
{
}

/*
	recursive depth-frist-search algorithm
*/
void Depth_First_Search::dfs(Maze* maze, Tile * tile)
{
    if (tile == maze->getEnd()) {
        finished = true; //stop search after end has been found
    }
    if (!tile->isVisited()) {
        tile->setVisited(true);
        vector<Tile*> neighbours = maze->getUnvisitedAccessibleNeighbours(tile->getY() / tileSize, tile->getX() / tileSize);
        for (int i = 0; i < neighbours.size(); i++) {
            if (!finished) {
                finalPath.insert(finalPath.end(), make_tuple(*tile, *neighbours.at(i)));
                dfs(maze, neighbours.at(i));
            }
        }
    }
}

vector<tuple<Tile, Tile>> Depth_First_Search::findPath(Maze maze)
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
    return finalPath;
}