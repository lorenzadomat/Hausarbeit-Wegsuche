#include <vector>
#include <string>
#include <queue>
#include <tuple>
#include <cmath>
#include <algorithm>
#include "config.h"
#include "Utils/Timer.cpp"
#include "Utils/Console.h"
#ifndef SEARCHALGORITHMS_H
#define SEARCHALGORITHMS_H

int curEndX = 0;
int curEndY = 0;

double distanceToPoint(int startY, int startX, int pEndY, int pEndX){
    return sqrt(pow(pEndX - startX, 2) + pow(pEndY - startY, 2) );
}

bool sortByDistanceToEnd(Tile* i, Tile* j){
    double iDist = distanceToPoint(i->getY(), i->getX(), curEndY, curEndX);
    double jDist = distanceToPoint(j->getY(), j->getX(), curEndY, curEndX);
    return iDist < jDist;
}

/**
 * Breadth First Search algorithm
 * @param maze
 * @return
 */
vector<tuple<Tile, Tile> > breadth_first_search(Maze maze){
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
    while(queue.size() > 0){
        tile = queue.front();
        if(tile == end){
            break;
        }
        vector<Tile*> neighbours = maze.getUnvisitedAccessibleNeighbours(tile->getY() / tileSize, tile->getX() / tileSize);
        for(int i = 0; i < neighbours.size(); i++){
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
/**
 * Breadth First Search algorithm Optimized
 * @param maze
 * @return
 */
vector<tuple<Tile, Tile>> breadth_first_search_optimized(Maze maze){
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
    while(queue.size() > 0 || found){
        sort(queue.begin(), queue.end(), sortByDistanceToEnd);
        //TODO Maybe self implemented insertion sort is quicker
        Tile* tile = queue.front();
        if(tile == maze.getEnd()){
            found = true;
            break;
        }
        vector<Tile*> neighbours = maze.getUnvisitedAccessibleNeighbours(tile->getY() / tileSize, tile->getX() / tileSize);
        for(int i = 0; i < neighbours.size(); i++){
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



#endif
