#include "Breadth_First_Search_Optimized.h"
#include <algorithm>

Breadth_First_Search_Optimized::Breadth_First_Search_Optimized()
{
	
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

	//Start Algorithm
	maze.getStart()->setVisited(true);
	queue.insert(queue.end(), maze.getStart());
	while (queue.size() > 0) {
		Tile* tile = queue.front();
        if (tile == maze.getEnd()) {
            goto end;
        }
		vector<Tile*> neighbours = maze.getUnvisitedAccessibleNeighbours(tile->getY() / tileSize, tile->getX() / tileSize);

		// Erase First Element and add new Neighbours to sorted vector
		// Insertion Sort, because it´s faster than the template sort-method
        queue.erase(queue.begin());
        for(int j = 0; j < neighbours.size(); j++){
            neighbours[j]->setVisited(true);
            finalPath.insert(finalPath.end(), make_tuple(*tile, *neighbours[j]));
            if (neighbours[j] == maze.getEnd()) {
                goto end;
            }

            double distance = distanceToPoint(neighbours[j]->getY(), neighbours[j]->getX(), maze.getEnd()->getY(), maze.getEnd()->getX());
            bool inserted = false;
            for (int i = 0; i < queue.size(); i++){
                if(distance < distanceToPoint(queue[i]->getY(), queue[i]->getX(), maze.getEnd()->getY(), maze.getEnd()->getX())){
                    queue.insert(queue.begin() + i, neighbours[j]);
                    inserted = true;
                    break;
                }
            }
            if(inserted == false){
                queue.insert(queue.end(), neighbours[j]);
            }
        }


	}
	//End Algorithm


	//End Timer
	end:
        timer.stop();
        printTableRow("Breadth_First_Search_Opt", timer.getDuration(), maze.getNumberOfCalls());
        return finalPath;
}

