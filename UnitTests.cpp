#define BOOST_TEST_MODULE Wegsuche
#include <boost/test/unit_test.hpp>
#include "Timer.hpp"
#include "Tile.hpp"
#include "Maze.hpp"
#include "SearchAlgorithms.hpp"


BOOST_AUTO_TEST_CASE( init ){
    BOOST_TEST_MESSAGE("Initializing Maze");
    BOOST_CHECK_EQUAL(2 + 2, 4);

}

BOOST_AUTO_TEST_CASE( example1 ){
    BOOST_TEST_MESSAGE("Initializing Maze");
    BOOST_CHECK_EQUAL(2 + 2, 4);
    BOOST_TEST_MESSAGE("Use Example Maze 1");

    BOOST_TEST_MESSAGE("Test Algorithms");

    BOOST_TEST_MESSAGE("Breadth First Search");

    BOOST_TEST_MESSAGE("Depth First Search");

    BOOST_TEST_MESSAGE("Dijkstra Algorithm");


}

BOOST_AUTO_TEST_CASE( example2 ){
    BOOST_TEST_MESSAGE("Initializing Maze");
    BOOST_CHECK_EQUAL(2 + 2, 4);
    BOOST_TEST_MESSAGE("Use Example Maze 2");

    BOOST_TEST_MESSAGE("Test Algorithms");
    BOOST_TEST_MESSAGE("Breadth First Search");

    BOOST_TEST_MESSAGE("Depth First Search");

    BOOST_TEST_MESSAGE("Dijkstra Algorithm");


}

BOOST_AUTO_TEST_CASE( random_maze ){
    BOOST_TEST_MESSAGE("Initializing Maze");
    BOOST_CHECK_EQUAL(2 + 2, 4);
    BOOST_TEST_MESSAGE("Use Random Maze");

    BOOST_TEST_MESSAGE("Test Algorithms");
    BOOST_TEST_MESSAGE("Breadth First Search");

    BOOST_TEST_MESSAGE("Depth First Search");

    BOOST_TEST_MESSAGE("Dijkstra Algorithm");


}
