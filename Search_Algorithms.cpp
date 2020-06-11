#include "Search_Algorithms.h"

double Search_Algorithms::distanceToPoint(int startY, int startX, int pEndY, int pEndX) {
    return sqrt(pow(pEndX - startX, 2) + pow(pEndY - startY, 2));
}
bool Search_Algorithms::sortByDistance(Tile* i, Tile* j){
    double iDist = distanceToPoint(i->getY(), i->getX(), curEndY, curEndX);
    double jDist = distanceToPoint(j->getY(), j->getX(), curEndY, curEndX);
    return iDist < jDist;
}