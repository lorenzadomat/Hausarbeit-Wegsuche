#include "config.h"
#include "Maze.cpp"
#include "Breadth_First_Search.cpp"
#include "Breadth_First_Search_Optimized.cpp"
#include "Depth_First_Search.cpp"
#include "Dijkstra_Algorithm.cpp"
#include "Utils/Console.h"
#include <vector>
#include <tuple>

Maze maze;
vector<vector<tuple<Tile, Tile>>> paths;
vector<int> pathWidth(5);
int algorithmNo = -1;
int mazeNo = -1;
int columns = -1;
int rows = -1;
int startX = -1;
int startY = -1;
int endX = -1;
int endY = -1;
bool drawInSteps = false;

void benchmark(Maze maze){
    paths.insert(paths.begin(), Breadth_First_Search().findPath(maze));
    paths.insert(paths.begin(), Breadth_First_Search_Optimized().findPath(maze));
    paths.insert(paths.begin(), Depth_First_Search().findPath(maze));
    paths.insert(paths.begin(), Dijkstra_Algorithm().findPath(maze));
}

void userInput(){
    string input;
    while(mazeNo == -1) {
        printMazeOptions();
        cin >> input;
        if (input == "Example_Maze" || input == "0") {
            mazeNo = 0;
            columns = 5;
            rows = 5;
            startX = 3;
            startY = 0;
            endX = 1;
            endY = 4;
            break;
        } else if (input == "Random_Maze" || input == "1") {
            mazeNo = 1;
            break;
        } else {
            cerr << "\033[1;31mInvalid Input\033[0m" << endl;
        }
    }
    cout << endl;
    if(mazeNo == 1){
        cin.exceptions(ios::failbit);
        cout << "Enter the number of rows" << endl;
        while (rows <= 0) {
            cout << "Rows = ";
            try {
                cin >> rows;
            }
            catch (ios::failure& e) {
                cerr << e.what() << endl;
                rows = -1;
                cin.clear();
                rewind(stdin);
            }
            if (rows <= 0) {
                cout << "Please enter a number greater than 0" << endl;
            }
        }
        cout << "Enter the number of columns" << endl;
        while (columns <= 0) {
            cout << "Columns = ";
            try {
                cin >> columns;
            }
            catch (ios::failure& e) {
                cerr << e.what() << endl;
                columns = -1;
                cin.clear();
                rewind(stdin);
            }
            if (columns <= 0) {
                cout << "Please enter a number greater than 0" << endl;
            }
        }
        cout << "Enter a Start-Point" << endl;
        while (startX < 0 || startX >= columns) {
            cout << "x = ";
            try {
                cin >> startX;
            }
            catch (ios::failure& e) {
                cerr << e.what() << endl;
                startX = -1;
                cin.clear();
                rewind(stdin);
            }
            if (startX < 0 || startX >= columns) {
                cout << "Please enter a number greater than or equal to 0 and less than " << columns << endl;
            }
        }
        while (startY < 0 || startY >= rows) {
            cout << "y = ";
            try {
                cin >> startY;
            }
            catch (ios::failure& e) {
                cerr << e.what() << endl;
                startY = -1;
                cin.clear();
                rewind(stdin);
            }
            if (startX < 0 || startX >= rows) {
                cout << "Please enter a number greater than or equal to 0 and less than " << rows << endl;
            }
        }
        cout << "Enter an End-Point" << endl;
        while (endX < 0 || endX >= columns) {
            cout << "x = ";
            try {
                cin >> endX;
            }
            catch (ios::failure& e) {
                cerr << e.what() << endl;
                endX = -1;
                cin.clear();
                rewind(stdin);
            }
            if (endX < 0 || endX >= columns) {
                cout << "Please enter a number greater than or equal to 0 and less than " << columns << endl;
            }
        }
        while (endY < 0 || endY >= rows) {
            cout << "y = ";
            try {
                cin >> endY;
            }
            catch (ios::failure& e) {
                cerr << e.what() << endl;
                endY = -1;
                cin.clear();
                rewind(stdin);
            }
            if (endY < 0 || endY >= rows) {
                cout << "Please enter a number greater than or equal to 0 and less than " << rows << endl;
            }
        }
    }
    cout << endl;
    while (algorithmNo == -1) {
        printAlgorithmOptions();
        cin >> input;
        if (input == "Breadth_First_Search" || input == "0") {
            algorithmNo = 0;
            break;
        }
        else if (input == "Breadth_First_Search_Opt" || input == "1") {
            algorithmNo = 1;
            break;
        }
        else if (input == "Depth_First_Search" || input == "2") {
            algorithmNo = 2;
            break;
        }
        else if (input == "Dijkstra" || input == "3") {
            algorithmNo = 3;
            break;
        }
        else if (input == "Benchmark" || input == "4") {
            algorithmNo = 4;
            break;
        } else if (input == "Exit" || input == "exit") {
            mazeNo = -1;
            algorithmNo = -1;
            userInput();
            return;
        } else {
            cout << "\033[1;31mInvalid Input\033[0m" << endl;
        }
    }

    cout << endl;
#ifdef makeGUI
    cout << "Draw in Steps? (Y / N): ";
        cin >> input;
        if(input == "Y" || input == "y"){
            drawInSteps = true;
        }
#endif





    // Select one mazes
    // If it´s a random Maze, ask for column and row length
    // Print all available Algorithms
}

void setup() {
    userInput();
    if(mazeNo != 1){
        maze = Maze(mazeNo);
    }else{
        maze = Maze(mazeNo , startX, startY, endX, endY, columns, rows);
    }

    xd::size(1200, 900);
    printTableHeader();
    if(algorithmNo == 0){
        paths.insert(paths.begin(), Breadth_First_Search().findPath(maze));
    }
    else if (algorithmNo == 1){
        paths.insert(paths.begin(), Breadth_First_Search_Optimized().findPath(maze));
    }
    else if (algorithmNo == 2) {
        paths.insert(paths.begin(), Depth_First_Search().findPath(maze));
    }
    else if (algorithmNo == 3){
        paths.insert(paths.begin(), Dijkstra_Algorithm().findPath(maze));
    }
    else if (algorithmNo == 4){
        //benchmark
        paths.insert(paths.begin(), Breadth_First_Search().findPath(maze));
        paths.insert(paths.begin(), Breadth_First_Search_Optimized().findPath(maze));
        paths.insert(paths.begin(), Depth_First_Search().findPath(maze));
        paths.insert(paths.begin(), Dijkstra_Algorithm().findPath(maze));
    }
    if (!drawInSteps) {
        for (int i = 0; i < paths.size(); i++) {
            pathWidth.at(i) = paths.at(i).size();
        }
    }
}

void draw() {
    // Draw Labyrinth
    xd::fill(glm::vec4(1, 1, 1, 1));
    xd::rect(0, 0, tileSize * (maze.getColumns() + 2), tileSize * (maze.getRows() + 2));
    for(int x = 0; x < maze.getColumns() ; x++){
        for(int y = 0; y < maze.getRows(); y++){
            if(maze.getTile(y, x)) {
                Tile* tile = maze.getTile(y, x);
                int xStart = tile->getX() + tileSize;
                int yStart = tile->getY() + tileSize;
                xd::fill(tile->getColor());
                xd::strokeWeight(0);
                xd::rect(xStart,  yStart, tileSize, tileSize);
                xd::strokeWeight(3);
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
    xd::strokeWeight(1.5);
    for (int j = 0; j < paths.size(); j++) {
        vector<tuple<Tile, Tile>> path = paths.at(j);

        switch (j) {
            case 0:
                xd::stroke(glm::vec4(1.0f, 1.0f, 0.0f, 1.0f)); //yellow
                break;
            case 1:
                xd::stroke(glm::vec4(1.0f, 0.6f, 0.0f, 1.0f)); //orange
                break;
            case 2:
                xd::stroke(glm::vec4(0.4f, 1.0f, 0.0f, 1.0f)); //green
                break;
            case 3:
                xd::stroke(glm::vec4(0.0f, 1.0f, 1.0f, 1.0f)); //turqoise
                break;
        }

        if (pathWidth.at(j) < path.size()) {
            pathWidth.at(j)++;
        }

        for (int i = 0; i < pathWidth.at(j); i++) {
            Tile start = get<0>(path[i]);
            Tile end = get<1>(path[i]);
            xd::line(start.getX() + tileSize / 2 + tileSize + (j*pow(-1, j)), start.getY() + tileSize / 2 + tileSize + (j*pow(-1, j)),
                     end.getX() + tileSize / 2 + tileSize + (j*pow(-1, j)), end.getY() + tileSize / 2 + tileSize + (j*pow(-1, j)));
        }
    }

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