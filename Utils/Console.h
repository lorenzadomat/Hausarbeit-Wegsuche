#ifndef CONSOLE_H
#define CONSOLE_H

#include <iomanip>

const char seperator = ' ';
const int algoWidth = 20;
const int durationWidth = 20;
const int callsWidth = 10;
const int mazeWidth = 20;
const int numberWidth = 5;

void printTableHeader(){
    cout << left << std::setw(algoWidth) << setfill(seperator) << "Algorithm";
    cout << "|";
    cout << left << std::setw(durationWidth) << setfill(seperator) << "\tDuration";
    cout << "|";
    cout << left << std::setw(callsWidth) << setfill(seperator) << "\tCalls";
    cout << left << endl;
    cout << left << std::setw(algoWidth + durationWidth + callsWidth + 10) << setfill('-') << "";
    cout << endl;
}
void printTableRow(string algorithm, float duration, int calls){
    string strDuration = std::to_string(std::lroundf(duration) / 1000000) + "ms";
    string tab = "\t";
    cout << left << std::setw(algoWidth) << setfill(seperator) << algorithm;
    cout << "|";
    cout << left << std::setw(durationWidth) << setfill(seperator) << ("\t" + strDuration);
    cout << "|";
    cout << left << std::setw(callsWidth) << setfill(seperator) << ("\t" + to_string(calls));
    cout << endl;
}

void printMazeOptions(){
    cout << left << endl;
    cout << left << std::setw(numberWidth) << setfill(seperator) << "No";
    cout << "|";
    cout << left << std::setw(mazeWidth) << setfill(seperator) << "\tMaze";
    cout << left << endl;

    cout << left << std::setw(numberWidth + mazeWidth + 6) << setfill('-') << "";
    cout << endl;

    cout << left << std::setw(numberWidth) << setfill(seperator) << "0";
    cout << "|";
    cout << left << std::setw(mazeWidth) << setfill(seperator) << "\tExample Maze 1";
    cout << left << endl;

    cout << left << std::setw(numberWidth) << setfill(seperator) << "1";
    cout << "|";
    cout << left << std::setw(mazeWidth) << setfill(seperator) << "\tExample Maze 2";
    cout << left << endl;

    cout << left << std::setw(numberWidth) << setfill(seperator) << "2";
    cout << "|";
    cout << left << std::setw(mazeWidth) << setfill(seperator) << "\tRandom Maze";
    cout << left << endl;

    cout << "Please select a maze: ";
}

void printAlgorithmOptions(){
    cout << left << endl;
    cout << left << std::setw(numberWidth) << setfill(seperator) << "No";
    cout << "|";
    cout << left << std::setw(algoWidth) << setfill(seperator) << "\tAlgorithm";
    cout << left << endl;

    cout << left << std::setw(numberWidth + algoWidth + 6) << setfill('-') << "";
    cout << endl;

    cout << left << std::setw(numberWidth) << setfill(seperator) << "0";
    cout << "|";
    cout << left << std::setw(algoWidth) << setfill(seperator) << "\tBreitensuche";
    cout << left << endl;

    cout << left << std::setw(numberWidth) << setfill(seperator) << "1";
    cout << "|";
    cout << left << std::setw(algoWidth) << setfill(seperator) << "\tBreitensuche2";
    cout << left << endl;

    cout << left << std::setw(numberWidth) << setfill(seperator) << "2";
    cout << "|";
    cout << left << std::setw(algoWidth) << setfill(seperator) << "\tDijkstra";
    cout << left << endl;

    cout << left << std::setw(numberWidth) << setfill(seperator) << "3";
    cout << "|";
    cout << left << std::setw(algoWidth) << setfill(seperator) << "\tBenchmark";
    cout << left << endl;

    cout << "Please select an Algorithm: ";
}



#endif