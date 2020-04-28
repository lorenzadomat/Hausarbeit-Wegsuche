#include "config.hpp"
#include "Maze.hpp"
#include "SearchAlgorithms.hpp"
#include <iostream>
#include <vector>
#include <tuple>
#include "libxd-0.3.2-Darwin/include/glm/glm.hpp"
#if gui == true
#include "./libxd-0.3.2-Darwin/include/xd/xd.hpp"
using namespace xd;
#else

void size(int x, int y){}
void line(int x1, int y1, int x2, int y2){}
void rect(int x1, int y1, int x2, int y2) {}
void stroke(glm::vec4 color){}
void strokeWeight(int w) {}
void noLoop(){}
void fill(glm::vec4 color){}

#endif

Maze maze(2, 3, 0, columns - 1, rows -1);
std::vector<tuple<Tile, Tile>> path, path1, path2;
std::string algorithm;

void setup() {
    //Start User Input

    //std::cin >> algorithm;
    //std::cout << "Algorithmus: " << algorithm;

    //End User Input
    std::cout << "Algorithm \t | \t Duration \t | \t Number of Calls \n";
    std::cout << "---------------------------------------------------------------- \n";
    size(640, 680);
    path1 = breadth_first_search(maze);
    path2 = breadth_first_search_optimized(maze);
    if(path1.size() <= path2.size()){
        path = path1;
    }else{
        path = path2;
    }

}

void draw() {

    rect(0, 0, tileSize * (rows + 2), tileSize * (columns + 2));
    for(int x = 0; x < rows ; x++){
        for(int y = 0; y < columns; y++){
            if(maze.getTile(y, x)) {
                Tile* tile = maze.getTile(y, x);
                int xStart = tile->getX() + tileSize;
                int yStart = tile->getY() + tileSize;
                fill(tile->getColor());
                strokeWeight(0);
                rect(xStart,  yStart, tileSize, tileSize);
                fill(vec4(1, 1, 1, 1));
                strokeWeight(2);
                stroke(glm::vec4(0, 0, 0, 1));
                if (!tile->getTop()) {
                    line(xStart, yStart, xStart + tileSize, yStart);
                }
                if (!tile->getRight()) {
                    line(xStart + tileSize, yStart, xStart + tileSize, yStart + tileSize);
                }
                if (!tile->getBottom()) {
                    line(xStart, yStart + tileSize, xStart + tileSize, yStart + tileSize);
                }
                if (!tile->getLeft()) {
                    line(xStart, yStart, xStart, yStart + tileSize);
                }
            }
        }
    }
    // Draw path
    strokeWeight(1);
    stroke(glm::vec4(1.0f, 0.8f, 0.1f, 1.0f));
    if(path.size() > 0){
        for(int i = 0; i < path.size() - 1; i++){
            Tile start = std::get<0>(path[i]);
            Tile end = std::get<1>(path[i]);;
            line(start.getX() + tileSize / 2 + tileSize, start.getY() + tileSize / 2 + tileSize, end.getX() + tileSize / 2 + tileSize, end.getY() + tileSize / 2 + tileSize);
        }
    }
    noLoop();

}

void destroy() {
}



#if gui == false
int main(){
        setup();
        draw();
        destroy();
        return 0;
    }
#endif
