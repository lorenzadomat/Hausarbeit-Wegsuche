#define BOOST_TEST_MODULE Wegsuche
#include <boost/test/unit_test.hpp>
#include <vector>
#include <tuple>
#include "Utils/Timer.cpp"
#include "config.h"
#include "Tile.cpp"
#include "Maze.cpp"
#include "Breadth_First_Search.cpp"
#include "Breadth_First_Search_Optimized.cpp"
#include "Depth_First_Search.cpp"
#include "Dijkstra_Algorithm.cpp"



BOOST_AUTO_TEST_CASE( init ){
    Maze maze = Maze(2, 3, 0, 1, 4, 5, 5);
    BOOST_TEST_MESSAGE("Check given parameters by using getter/setter methods");
    BOOST_CHECK_EQUAL(maze.getStart()->getX() / tileSize, 3);
    BOOST_CHECK_EQUAL(maze.getStart()->getY() / tileSize, 0);
    BOOST_CHECK_EQUAL(maze.getEnd()->getX() / tileSize, 1);
    BOOST_CHECK_EQUAL(maze.getEnd()->getY() / tileSize, 4);
    BOOST_CHECK_EQUAL(maze.getColumns(), 5);
    BOOST_CHECK_EQUAL(maze.getRows(), 5);

    BOOST_TEST_MESSAGE("Check neighbour methods");
    /**
     * Top left hand corner can´t have top and left neighbour
     * Bottom right hand corner can´t have bottom and right neighbour
     */
    BOOST_CHECK_EQUAL(maze.getTopNeighbour(0,0), nullptr);
    BOOST_CHECK_EQUAL(maze.getLeftNeighbour(0,0), nullptr);
    BOOST_CHECK_EQUAL(maze.getBottomNeighbour(4,4), nullptr);
    BOOST_CHECK_EQUAL(maze.getRightNeighbour(4,4), nullptr);

    maze.getTile(0,0)->setVisited(true);
    BOOST_CHECK_EQUAL(maze.getTile(0,0)->isVisited(), true);
    BOOST_TEST_MESSAGE("Check reset method");
    maze.reset();
    BOOST_CHECK_EQUAL(maze.getTile(0,0)->isVisited(), false);

}

BOOST_AUTO_TEST_CASE( Example_Maze1 ){

    BOOST_TEST_MESSAGE("Initializing Maze 1");
    Maze maze = Maze(0);
    BOOST_TEST_MESSAGE("Check unvisited neighbours of Tile(3, 3) having its borders on the left and top site");
    BOOST_CHECK_EQUAL(maze.getUnvisitedNeighbours(3, 3).size(), 4); // All neighbours are unvisited, because no algorithm has been executed yet

    /**
     * Set right neighbour of Tile(3,3) visited, which is accessible
     */
    maze.getTile(3, 4)->setVisited(true);
    BOOST_CHECK_EQUAL(maze.getUnvisitedNeighbours(3, 3).size(), 3);
    BOOST_CHECK_EQUAL(maze.getUnvisitedAccessibleNeighbours(3, 3).size(), 1);
    BOOST_CHECK_EQUAL(maze.getUnvisitedAccessibleNeighbours(3, 3).at(0), maze.getBottomNeighbour(3,3));

}

BOOST_AUTO_TEST_CASE( Search_Algorithm_Test ){
    BOOST_TEST_MESSAGE("Initializing Maze");
    Maze maze = Maze(0);
    Maze maze0 = Maze(2, 0, 0, 0, 0, 10, 10);

    /**
     * Verify that for every search algorithm the last element in path equals the end of maze every time (50 runs).
     */
    BOOST_TEST_MESSAGE("Breadth First Search");
    for(int i = 0; i < 50; i++){
        vector<tuple<Tile, Tile>> path = Breadth_First_Search().findPath(maze);
        BOOST_TEST(get<1>(path.at(path.size()-1)) == *maze.getEnd());
    }
    BOOST_TEST_MESSAGE("Breadth First Search Optimized");
    for(int i = 0; i < 50; i++){
        vector<tuple<Tile, Tile>> path = Breadth_First_Search_Optimized().findPath(maze);
        BOOST_TEST(get<1>(path.at(path.size()-1)) == *maze.getEnd());
    }

    BOOST_TEST_MESSAGE("Depth First Search");
    for(int i = 0; i < 50; i++){
        vector<tuple<Tile, Tile>> path = Depth_First_Search().findPath(maze);
        BOOST_TEST(get<1>(path.at(path.size()-1)) == *maze.getEnd());
    }

    BOOST_TEST_MESSAGE("Dijkstra Algorithm");
    for(int i = 0; i < 50; i++){
        vector<tuple<Tile, Tile>> path = Dijkstra_Algorithm().findPath(maze);
        BOOST_TEST(get<1>(path.at(path.size()-1)) == *maze.getEnd());
    }


    BOOST_TEST_MESSAGE("Set Start == End");
    BOOST_CHECK_EQUAL(Breadth_First_Search().findPath(maze0).size(),0);
    BOOST_CHECK_EQUAL(Breadth_First_Search_Optimized().findPath(maze0).size(),0);
    BOOST_CHECK_EQUAL(Depth_First_Search().findPath(maze0).size(),0);
    BOOST_CHECK_EQUAL(Dijkstra_Algorithm().findPath(maze0).size(),0);




}

