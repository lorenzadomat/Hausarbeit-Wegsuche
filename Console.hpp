#include <iomanip>
#ifndef HAUSARBEITWEGSUCHE_CONSOLE_HPP
#define HAUSARBEITWEGSUCHE_CONSOLE_HPP

const char seperator = ' ';
const int algoWidth = 20;
const int durationWidth = 20;
const int callsWidth = 10;

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

#endif
