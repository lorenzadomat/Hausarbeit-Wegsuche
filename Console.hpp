//
// Created by l.adomat on 28.04.20.
//

#include <iostream>
#include <iomanip>
#ifndef HAUSARBEITWEGSUCHE_CONSOLE_HPP
#define HAUSARBEITWEGSUCHE_CONSOLE_HPP

const char seperator = ' ';
const int algoWidth = 20;
const int durationWidth = 20;
const int callsWidth = 10;

void printTableHeader(){
    std::cout << left << std::setw(algoWidth) << setfill(seperator) << "Algorithm";
    std::cout << left << std::setw(durationWidth) << setfill(seperator) << "Duration";
    std::cout << left << std::setw(callsWidth) << setfill(seperator) << "Calls";
    std::cout << left << endl;
    std::cout << left << std::setw(algoWidth + durationWidth + callsWidth) << setfill('-') << "";
    std::cout << endl;
}
void printTableRow(string algorithm, float duration, int calls){
    string strDuration = std::to_string(std::lroundf(duration)) + "ms";
    std::cout << left << std::setw(algoWidth) << setfill(seperator) << algorithm;
    std::cout << left << std::setw(durationWidth) << setfill(seperator) << strDuration;
    std::cout << left << std::setw(callsWidth) << setfill(seperator) << calls;
    std::cout << endl;
}

#endif
