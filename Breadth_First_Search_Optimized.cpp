#include "Breadth_First_Search_Optimized.h"

Breadth_First_Search_Optimized::Breadth_First_Search_Optimized()
{
	
}

double Breadth_First_Search_Optimized::distanceToPoint(int startY, int startX, int pEndY, int pEndX) {
	return sqrt(pow(pEndX - startX, 2) + pow(pEndY - startY, 2));
}

bool Breadth_First_Search_Optimized::sortByDistanceToEnd(Tile* i, Tile* j) {
	double iDist = distanceToPoint(i->getY(), i->getX(), curEndY, curEndX);
	double jDist = distanceToPoint(j->getY(), j->getX(), curEndY, curEndX);
	return iDist < jDist;
}

/**
 * Breadth First Search algorithm Optimized
 * @param maze
 * @return
 */
vector<tuple<Tile, Tile>> Breadth_First_Search_Optimized::findPath(Maze maze) {
	maze.reset();
	vector<tuple<Tile, Tile>> finalPath;
	vector<Tile*> queue;
	Timer timer;

	//Start Timer
	timer.start();

	curEndX = maze.getEnd()->getX();
	curEndY = maze.getEnd()->getY();
	//Start Algorithm
	maze.getStart()->setVisited(true);
	queue.insert(queue.end(), maze.getStart());
	bool found = false;
	while (queue.size() > 0 || found) {
		//sort(queue.begin(), queue.end(), sortByDistanceToEnd);
		//TODO Maybe self implemented insertion sort is quicker
		Tile* tile = queue.front();
		if (tile == maze.getEnd()) {
			found = true;
			break;
		}
		vector<Tile*> neighbours = maze.getUnvisitedAccessibleNeighbours(tile->getY() / tileSize, tile->getX() / tileSize);
		for (int i = 0; i < neighbours.size(); i++) {
			neighbours[i]->setVisited(true);
			queue.insert(queue.end(), neighbours[i]);
			finalPath.insert(finalPath.end(), make_tuple(*tile, *neighbours[i]));
		}
		queue.erase(queue.begin());

	}
	//End Algorithm


	//End Timer
	timer.stop();
	printTableRow("Breitensuche2", timer.getDuration(), maze.getNumberOfCalls());
	return finalPath;
}

