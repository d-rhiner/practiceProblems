//
// Created by dakot on 3/25/2020.

#include <cstdlib>
#include <fstream>
class Rectangle {
public:
    void calcLength() {
        length = abs(lowLeftx) + abs(upRightx);
    }
    void calcHeight() {
        height = abs(lowLefty) + abs(upRighty);
    }
    void calcArea() {
        area = length*height;
    }
    int getArea() {
        return area;
    }

    int getLength() {
        return length;
    }
    int getHeight() {
        return height;
    }
    friend std::istream &operator>>(std::istream &rectIn, Rectangle &R) {
        rectIn >> R.lowLeftx >> R.lowLefty >> R.upRightx >> R.upRighty;
    }
    Rectangle &operator=(const Rectangle &copyRec) {
        upRightx = copyRec.upRightx;
        lowLeftx = copyRec.lowLeftx;
        lowLefty  = copyRec.lowLefty;
        upRighty = copyRec.upRighty;
        area = copyRec.area;
        length = copyRec.length;
        height = copyRec.height;
    }

private:

    int upRightx;
    int lowLeftx;
    int lowLefty;
    int upRighty;
    int area;
    int length;
    int height;
};



#include <iostream>
#include <vector>

using namespace std;

void sortAreas(std::vector<Rectangle> &recs) {
    int i, j, min;
    Rectangle temp;
    for (i = 0; i < recs.size()-1; i++) {
        min = i;
            for (j = i+1; j < recs.size(); j++) {
                if (recs[j].getArea() < recs[min].getArea())
                    min = j;
                if (min != i) {
                    temp = recs[i];
                    recs[i] = recs[min];
                    recs[min] = temp;
            }
        }
    }
}
bool viable(std::vector<Rectangle> recs, Rectangle bigRec){
    for (int i = 0; i < recs.size(); i++) {
        if (recs[i].getLength() > bigRec.getLength() || recs[i].getHeight() > bigRec.getHeight())
            return false;
    }
    return true;
}

int main() {

    ifstream inFile;
    ofstream outFile;
    string filename;

    int testCases;
    int rectangleCount;
    Rectangle biggestRec;
    Rectangle currRect;
    std::vector<Rectangle> recList;

    cout << "Please enter the name of the file with the input values." << endl;
    cin >> filename;
    inFile.open(filename.c_str());

    if (inFile.is_open()) {
        inFile >> testCases;

        for (int i = 0; i < testCases; i++) {
            inFile >> rectangleCount;
            for (int j = 0; j < rectangleCount; j++) {
                inFile >> currRect;
                recList.push_back(currRect);
            }
            sortAreas(recList);
            biggestRec = recList[0];
            if (!viable(recList, biggestRec))
                cout << '-1' << endl;
            else {
                // do more shit here
                cout << "wow good for you." << endl;
            }
        }
    }
    else {
        cout << "ERROR: invalid filename." << endl;
    }
}




