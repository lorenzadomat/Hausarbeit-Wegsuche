#include "Dijkstra_Algorithm.h"

Dijkstra_Algorithm::Dijkstra_Algorithm(){

}

/**
 * Dijkstra algorithm
 * @param maze
 * @return finalPath
 */
vector<tuple<Tile, Tile> > Dijkstra_Algorithm::findPath(Maze maze) {
	//Start Timer
	Timer timer;
	timer.start();

	//init
	maze.reset();
	vector<tuple<Tile, Tile> > finalPath;
	vector<Tile*> allTiles;
	vector<Tile*> neighbours;
	Tile* predecessor;
	Tile* tile = maze.getStart();
	Tile* end = maze.getEnd();
	int bfrDist = INT_MAX;
	int alternativeDist;
	int delIndex;
	int distance = 0;

	for (int x = 0; x < maze.getColumns(); x++) {
		for (int y = 0; y < maze.getRows(); y++) {
			allTiles.insert(allTiles.end(), maze.getTile(y, x));
			allTiles.at(x * maze.getRows() + y)->setDistance(INT_MAX);
			allTiles.at(x * maze.getRows() + y)->setPredecessor(nullptr);
		}

		tile->setDistance(0); //obviously the distance from start to start equals 0 
	}
	//Start Algorithm
	while (!allTiles.empty() && bfrDist <= end->getDistance()) {
		//find tile with lowest distance from start 
		bfrDist = INT_MAX;
		for (int i = 0; i < allTiles.size(); i++) {
			if (allTiles.at(i)->getDistance() < bfrDist) {
				tile = allTiles.at(i);
				bfrDist = tile->getDistance();
				neighbours = maze.getUnvisitedAccessibleNeighbours(tile->getY() / tileSize, tile->getX() / tileSize);
				delIndex = i;
			}
		}
		allTiles.erase(allTiles.begin() + delIndex);

		//update distance
		alternativeDist = bfrDist + 1; //all neighbours have distance 1 
		for (int i = 0; i < neighbours.size(); i++) {
			if (alternativeDist < neighbours.at(i)->getDistance()) {
				neighbours.at(i)->setDistance(alternativeDist);
				neighbours.at(i)->setPredecessor(tile);
			}
		}
	}
	//End Algorithm

	//End Timer
	timer.stop();
	printTableRow("Dijkstra-Algorithm", timer.getDuration(), maze.getNumberOfCalls());
    this->setDuration(timer.getDuration());

	//create final path
	tile = end;
	while (tile->getPredecessor() != nullptr) {
		finalPath.insert(finalPath.end(), make_tuple(*tile, *tile->getPredecessor()));
		tile = tile->getPredecessor();
	}
	return finalPath;
}