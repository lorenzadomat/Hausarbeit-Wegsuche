//
// Created by l.adomat on 26.04.20.
//
#include <vector>
#include <string>
#include <iostream>
#include <queue>
#include <tuple>
#include <cmath>
#include "config.hpp"
#include "Timer.hpp"
#ifndef HAUSARBEITWEGSUCHE_SEARCHALGORITHMS_HPP
#define HAUSARBEITWEGSUCHE_SEARCHALGORITHMS_HPP

using namespace std;

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

void printResult(std::string algorithm, float duration, int numberOfCalls){
    std::cout << algorithm << " \t | \t " << duration / 1000000 << "ms \t | \t " << numberOfCalls << "\n";
}



/**
 * Breadth First Search algorithm
 * @param maze
 * @return
 */
std::vector<tuple<Tile, Tile>> breadth_first_search(Maze maze){
    maze.reset();
    std::vector<tuple<Tile, Tile>> finalPath;
    std::queue<Tile*> queue;
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
        std::vector<Tile*> neighbours = maze.getUnvisitedAccessibleNeighbours(tile->getY() / tileSize, tile->getX() / tileSize);
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
    printResult("Breitensuche", timer.getDuration(), maze.getNumberOfCalls());
    return finalPath;

}
/**
 * Breadth First Search algorithm Optimized
 * @param maze
 * @return
 */
std::vector<tuple<Tile, Tile>> breadth_first_search_optimized(Maze maze){
    maze.reset();
    std::vector<tuple<Tile, Tile>> finalPath;
    std::vector<Tile*> queue;
    Timer timer;

    //Start Timer
    timer.start();

    //Start Algorithm
    maze.getStart()->setVisited(true);
    queue.insert(queue.end(), maze.getStart());
    while(queue.size() > 0){
        std::sort(queue.begin(), queue.end(), sortByDistanceToEnd);
        Tile* tile = queue.front();
        if(tile == maze.getEnd()){
            break;
        }
        std::vector<Tile*> neighbours = maze.getUnvisitedAccessibleNeighbours(tile->getY() / tileSize, tile->getX() / tileSize);
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
    printResult("Breitensuche2", timer.getDuration(), maze.getNumberOfCalls());
    return finalPath;
}



#endif //HAUSARBEITWEGSUCHE_SEARCHALGORITHMS_HPP
