#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

int presentMaterial(string dimensions, string type) {
    stringstream ss(dimensions);
    string dimension;
    vector<int> dimensionVec;

    while(getline(ss, dimension, 'x')) {
        dimensionVec.push_back(stoi(dimension));
    }

    sort(dimensionVec.begin(), dimensionVec.end());
    int material;
    if (type == "paper") {
        material = 3*dimensionVec[0]*dimensionVec[1] +
                2*dimensionVec[1]*dimensionVec[2] +
                2*dimensionVec[0]*dimensionVec[2];
    }
    else if (type == "ribbon") {
        material = 2*dimensionVec[0] + 2*dimensionVec[1] +
                dimensionVec[0]*dimensionVec[1]*dimensionVec[2];
    }

    return material;
}

int day2a(string file) {
    fstream fs(file);
    string dimensions;
    int totalPaper = 0;

    while (getline(fs, dimensions)) {
        totalPaper+= presentMaterial(dimensions, "paper");
    }

    return totalPaper;
}

int day2b(string file) {
    fstream fs(file);
    string dimensions;
    int totalPaper = 0;

    while (getline(fs, dimensions)) {
        totalPaper+= presentMaterial(dimensions, "ribbon");
    }

    return totalPaper;
}



int main() {
    cout << day2b("../Resources/input.txt") << endl;
}