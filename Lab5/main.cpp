#include <iostream>
#include <fstream>
#include <sstream>
#include <math.h>
#include <chrono>

using namespace std;

void readFile(string &str, string &fileName) {
    cout << "FILE " << fileName << endl ;
    ifstream inFile;
    inFile.open(fileName);

    stringstream strStream;
    strStream << inFile.rdbuf();
    str = strStream.str();
    inFile.close();
}

int hashing(string pattern) {
    int hashedNum = 0;

    for(int i = 0; i < pattern.size(); i++) {
        hashedNum += pattern[i] * pow(10, pattern.size() - i - 1) ;
    }
    return hashedNum;
}

void rolling(string& str, string& pattern) {
    int patternSize = pattern.size();
    int patternHashing = hashing(pattern);

    int hashingNum;

    for(int i = 0; i < str.size(); i++) {
        hashingNum = hashing(str.substr(i,patternSize));
        if(patternHashing == hashingNum) {
            for(int j = 0; j < patternSize; j++){
                if(pattern[j] == str[i + j]) {
                    continue;
                } else {
                    break;
                }
            }
        }
    }
}

int countTimeOfExecution(string& pattern, string fileName) {
    string str;
    readFile(str, fileName);
    auto started = chrono::high_resolution_clock::now();
    rolling(str,pattern);
    auto done = chrono::high_resolution_clock::now();
    return chrono::duration_cast<chrono::nanoseconds>(done-started).count();
}

int main() {
    string pattern = "ere";

    cout << countTimeOfExecution(pattern, "input") << endl;
    cout << countTimeOfExecution(pattern, "input2") << endl;
    cout << countTimeOfExecution(pattern, "input3") << endl;

    return 0;
}
