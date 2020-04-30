#include <vector>
#include <string>
#include <queue>
#include <tuple>
#include <cmath>
#include <algorithm>
#include "config.hpp"
#include "Timer.hpp"
#include "Console.hpp"
#ifndef HAUSARBEITWEGSUCHE_SEARCHALGORITHMS_HPP
#define HAUSARBEITWEGSUCHE_SEARCHALGORITHMS_HPP

int curX = 0;
int curY = 0;

double distanceToPoint(int startY, int startX, int endY, int endX){
    return sqrt(pow(endX - startX, 2) + pow(endY - startY, 2) );
}

bool sortByDistanceToEnd(Tile* i, Tile* j){
    double iDist = distanceToPoint(i->getY(), i->getX(), curY, curX);
    double jDist = distanceToPoint(j->getY(), j->getX(), curY, curX);
    return iDist > jDist;
}

/**
 * Breadth First Search algorithm
 * @param maze
 * @return
 */
vector<tuple<Tile, Tile>> breadth_first_search(Maze maze){
    maze.reset();
    vector<tuple<Tile, Tile>> finalPath;
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

    //Start Algorithm
    maze.getStart()->setVisited(true);
    queue.insert(queue.end(), maze.getStart());
    bool found = false;
    while(queue.size() > 0 || found){
        sort(queue.begin(), queue.end(), sortByDistanceToEnd);
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
