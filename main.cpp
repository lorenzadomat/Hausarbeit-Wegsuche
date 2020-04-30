#define preventGUI
#include "config.hpp"
#include "Maze.hpp"
#include "SearchAlgorithms.hpp"
#include "Console.hpp"
#include <vector>
#include <tuple>

#if gui == true
    cout << "hallo"
#endif

Maze maze(2, 3, 0, columns - 1, rows -1);
vector<tuple<Tile, Tile>> path, path1, path2;
string algorithm = "Breitensuche";

void benchmark(){
    path1 = breadth_first_search(maze);
    path2 = breadth_first_search_optimized(maze);
    if(path1.size() <= path2.size()){
        path = path1;
    }else{
        path = path2;
    }
}

void userInput(){

    // Select one mazes
    // If it´s a random Maze, ask for column and row length
    // Print all available Algorithms
}

void setup() {
    userInput();
    xd::size(640, 680);
    printTableHeader();
    if(algorithm == "Breitensuche"){
        path = breadth_first_search(maze);
    }else if (algorithm == "Breitensuche2"){
        path = breadth_first_search_optimized(maze);
    }else if (algorithm == "Benchmark"){
        benchmark();
    }
}

void draw() {
    // Draw Labyrinth
    xd::fill(glm::vec4(1, 1, 1, 1));
    xd::rect(0, 0, tileSize * (rows + 2), tileSize * (columns + 2));
    for(int x = 0; x < rows ; x++){
        for(int y = 0; y < columns; y++){
            if(maze.getTile(y, x)) {
                Tile* tile = maze.getTile(y, x);
                int xStart = tile->getX() + tileSize;
                int yStart = tile->getY() + tileSize;
                xd::fill(tile->getColor());
                xd::strokeWeight(0);
                xd::rect(xStart,  yStart, tileSize, tileSize);
                xd::strokeWeight(2);
                xd::stroke(glm::vec4(0, 0, 0, 1));
                if (!tile->getTop()) {
                    xd::line(xStart, yStart, xStart + tileSize, yStart);
                }
                if (!tile->getRight()) {
                    xd::line(xStart + tileSize, yStart, xStart + tileSize, yStart + tileSize);
                }
                if (!tile->getBottom()) {
                    xd::line(xStart, yStart + tileSize, xStart + tileSize, yStart + tileSize);
                }
                if (!tile->getLeft()) {
                    xd::line(xStart, yStart, xStart, yStart + tileSize);
                }
            }
        }
    }
    // Draw path
    xd::strokeWeight(1);
    xd::stroke(glm::vec4(1.0f, 0.8f, 0.1f, 1.0f));
    if(path.size() > 0){
        for(int i = 0; i < path.size() - 1; i++){
            Tile start = get<0>(path[i]);
            Tile end = get<1>(path[i]);;
            xd::line(start.getX() + tileSize / 2 + tileSize, start.getY() + tileSize / 2 + tileSize, end.getX() + tileSize / 2 + tileSize, end.getY() + tileSize / 2 + tileSize);
        }
    }
    //xd::noLoop();

}

void destroy() {
}

#ifndef makeGUI
int main(){
    setup();
    //draw();
    //destroy();
    return 0;
}
#endif