#include <iostream>
#include <map>
#include <cmath>
#include <iomanip>
#include <queue>
#include <string>

using namespace std;

float findMax(float a, float b) {
    return a > b ? a : b;
}

float calculateHypotenuse(float heightCatet, float widthCatet) {
    return sqrt((heightCatet*heightCatet) + (widthCatet*widthCatet));
}

float dynamicRecursion(int index, float currentVal, vector<float>& vectorOfNums, float widthCatet,queue<float>& queue) {
    static bool wasAtTheEnd = false;

    if(index + 1 == vectorOfNums.size()) {
        return currentVal;
    }

    float left, right;
    if(wasAtTheEnd) {
        left = queue.front();
        queue.pop();
        right = queue.front();
        queue.pop();
    }
    else {
        left = dynamicRecursion(index + 1, vectorOfNums[index+ 1], vectorOfNums, widthCatet, queue);
        wasAtTheEnd = true;
        right = dynamicRecursion(index + 1, 1, vectorOfNums,widthCatet, queue);

        queue.push(left);
        queue.push(right);
    }

    float leftHypotenuse = calculateHypotenuse(vectorOfNums[index + 1]-currentVal, widthCatet);
    float rightHypotenuse = calculateHypotenuse(1-currentVal, widthCatet);

    if(index + 2 != vectorOfNums.size())
        currentVal = findMax(leftHypotenuse + left,rightHypotenuse + right);
    else {
        currentVal = findMax(leftHypotenuse,rightHypotenuse);
    }

    return currentVal;
}

void readInput(vector<float>& vectorOfNums, float &widthCatet) {
    string fitstLineInput;
    if( getline( cin, fitstLineInput ))  {
        istringstream str(fitstLineInput);
        str >> widthCatet;
        while(str >> widthCatet){
        }
    }

    string secondLineInput;
    if ( getline(cin, secondLineInput) ) {
        istringstream str(secondLineInput);
        float value;
        str >> value;
        vectorOfNums.push_back( value );
        while ( str >> value ) {
            vectorOfNums.push_back( value );
        }
    }
}

float returnMaxValue(vector<float>& vectorOfNums, float widthCatet, queue<float>& queue) {
    float maxValue = dynamicRecursion(0,vectorOfNums[0],vectorOfNums,widthCatet,queue);
    if(vectorOfNums[0] != 1) {
        vectorOfNums[0] = 1;
        float maxValueRight = dynamicRecursion(0,vectorOfNums[0],vectorOfNums,widthCatet,queue);
        maxValue = findMax(maxValue,maxValueRight);
    }
    return maxValue;
}


int main() {
    float widthCatet = 0;
    vector<float> vectorOfNums;
    queue<float> queue;
    readInput(vectorOfNums, widthCatet);

    cout << "max value " << fixed << setprecision(2) << returnMaxValue(vectorOfNums, widthCatet,queue);
    return 0;
}











//
//#include <iostream>
//#include <map>
//#include <math.h>
//using namespace std;
//
//float findMax(float a, float b) {
//    return a > b ? a : b;
//}
//
//float calculateHypotenuse(float heightCatet, float widthCatet) {
//    return sqrt((heightCatet*heightCatet) + (widthCatet*widthCatet));
//}
////map<int,float>& dictOfNums
//float recursion(int index, float currentVal, map<int,float>& dictOfNums, float widthCatet) {
////    if(index == dictSize) {
////
////    }
//    if(index + 1== dictOfNums.size()) {
//        return currentVal;
//    }
//
////    if(index  != dictOfNums.size()) {
//    float left = recursion(index + 1, dictOfNums[index+ 1], dictOfNums, widthCatet);
////    float leftHypotenuse = calculateHypotenuse(left-dictOfNums[index], widthCatet);
//    float leftHypotenuse = calculateHypotenuse(dictOfNums[index + 1]-currentVal, widthCatet);
//
//    float right = recursion(index + 1, 1, dictOfNums,widthCatet);
////    float rightHypotenuse = calculateHypotenuse(right-dictOfNums[index], widthCatet);
//    float rightHypotenuse = calculateHypotenuse(1-currentVal, widthCatet);
//
//    if(index + 2 != dictOfNums.size())
//        currentVal = findMax(leftHypotenuse + left,rightHypotenuse + right);
//    else {
//        currentVal = findMax(leftHypotenuse,rightHypotenuse);
//    }
//    //    }
//
//    return currentVal;
//}
//
//int main() {
//    float arrOfNums[] = { 2, 3, 4, 5};
////    float arrOfNums[] = { 56, 18, 17, 94, 23, 7, 21, 94, 29, 54, 44, 26, 86, 79, 4, 15, 5, 91, 25, 17, 88, 66, 28, 2, 95, 97, 60, 93, 40, 70, 75, 48, 38, 51, 34, 52, 87, 8, 62, 77, 35, 52, 3, 93, 34, 57, 51, 11, 39, 72
////    };
//    map<int, float> dictOfNums;
//    for(int i = 0; i < sizeof (arrOfNums) / sizeof (float ); i++) {
//        dictOfNums[i] = arrOfNums[i];
//    }
////    float arrayOfMaxValues;
////    float maxValue;
//    float widthCatet = 1;
////    float widthCatet = 4;
//    float maxValue = recursion(0,dictOfNums[0],dictOfNums,widthCatet);
//    if(dictOfNums[0] != 1) {
//        dictOfNums[0] = 1;
//        float maxValueRight = recursion(0,dictOfNums[0],dictOfNums,widthCatet);
//        maxValue = findMax(maxValue,maxValueRight);
//    }
//
//    cout << "max value " << maxValue;
//
//    return 0;
//}
