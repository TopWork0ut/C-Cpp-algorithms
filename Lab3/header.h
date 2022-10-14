#pragma once
#ifndef LAB3_HEADER_H
#define LAB3_HEADER_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <map>

using namespace std;

class TopologicalSorting {
public :
    TopologicalSorting(vector<string> [],int);
    vector<string> sortByTopological();

private :
    void visitVertex(int index);
    int sizeOfArray;
    vector<string> * vectorOfCaptions;
    vector<string> unsortedStrings;
    vector<string> sortedStrings;
    vector<int>	* digitEq;
    vector<int> indexesOfSorted;
    vector<bool> isVertexVisited;
};

#endif //LAB3_HEADER_H
