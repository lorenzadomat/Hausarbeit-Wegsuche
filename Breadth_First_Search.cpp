#include "Breadth_First_Search.h"


Breadth_First_Search::Breadth_First_Search()
{
}

/**
 * Breadth First Search algorithm
 * @param maze
 * @return
 */
vector<tuple<Tile, Tile>> Breadth_First_Search::findPath(Maze maze) {
	maze.reset();
	vector<tuple<Tile, Tile> > finalPath;
	queue<Tile*> queue;
	Timer timer;
	//Start Timer
	timer.start();

	//Start Algorithm
	Tile* tile = maze.getStart();
	Tile* end = maze.getEnd();
	tile->setVisited(true);
	queue.push(tile);
	while (queue.size() > 0) {
		tile = queue.front();
		if (tile == end) {
			break;
		}
		vector<Tile*> neighbours = maze.getUnvisitedAccessibleNeighbours(tile->getY() / tileSize, tile->getX() / tileSize);
		for (int i = 0; i < neighbours.size(); i++) {
			neighbours[i]->setVisited(true);
			queue.push(neighbours[i]);
			finalPath.insert(finalPath.end(), make_tuple(*tile, *neighbours[i]));
		}
		queue.pop();

	}
	//End Algorithm

	//End Timer
	timer.stop();
	printTableRow("Breitensuche", timer.getDuration(), maze.getNumberOfCalls());
	return finalPath;

}