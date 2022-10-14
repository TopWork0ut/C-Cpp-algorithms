#include "header.h"

TopologicalSorting::TopologicalSorting(vector<string> * captions, int size) {
    vectorOfCaptions = captions;
    sizeOfArray = size;
    digitEq = new vector<int>[sizeOfArray];
    for (int i =0; i < sizeOfArray; i++) {
        isVertexVisited.push_back(false);
        unsortedStrings.push_back(vectorOfCaptions[i].at(0));
    }
    for(int i =0; i < sizeOfArray; i++) {
        for(auto it = vectorOfCaptions[i].begin(); it < vectorOfCaptions[i].end();++it) {
            auto index = find(unsortedStrings.begin(),unsortedStrings.end(),*it);
            if(index != unsortedStrings.end() ) {
                digitEq[i].push_back(index - unsortedStrings.begin());
            }
        }
    }
}

vector<string> TopologicalSorting::sortByTopological() {
    for(int i = 0; i < sizeOfArray; i++) {
        if(!isVertexVisited[i])
            visitVertex(i);
    }

    for(int i = 0; i < indexesOfSorted.size();i++) {
        sortedStrings.push_back(unsortedStrings[indexesOfSorted[i]]);
    }
    return sortedStrings;
}

void TopologicalSorting::visitVertex(int index) {
    isVertexVisited[index] = true;

    for(vector<int>::iterator i = digitEq[index].begin(); i<digitEq[index].end(); i++) {
        if(!isVertexVisited[*i])
            visitVertex(*i);
    }
    indexesOfSorted.push_back(index);
}

void readAndWriteToFile() {
    ifstream InputFile;
    InputFile.open ("govern.in");
    if (InputFile.is_open()) {
        vector<string> headers[8];
        string firstWordInLine, secondWordInLine;
        map<string, int> mapOfHeaders;
        int i = 0;
        while (InputFile >> firstWordInLine >> secondWordInLine) {
            if (i == 0) {
                headers[i].insert(headers[i].end(), firstWordInLine);
            }
            if (mapOfHeaders.find(secondWordInLine) == mapOfHeaders.end()) {
                mapOfHeaders.insert({secondWordInLine, ++i});
                headers[i].insert(headers[i].begin(), secondWordInLine);
                headers[i].insert(headers[i].end(), firstWordInLine);
            } else {
                headers[mapOfHeaders.at(secondWordInLine)].insert(headers[mapOfHeaders.at(secondWordInLine)].end(), firstWordInLine);
            }
        }
        TopologicalSorting Sorting(headers, 8);
        vector<string> sorted = Sorting.sortByTopological();
        ofstream OutputFile("govern.out");
        for (int i = sorted.size() - 1; i >= 0; i--) {
            OutputFile << sorted[i] << endl;
        }
        OutputFile.close();
    }
    InputFile.close();
}

int main() {
    readAndWriteToFile();
    return 0;
}
