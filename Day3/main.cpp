#include <iostream>
#include <fstream>
#include <unordered_set>
#include <utility>
#include <map>
using namespace std;

void updateSanta(char operation, int &x, int &y, int &count, map<pair<int, int>, bool> &visitedCoords) {
    if (operation == '^') {
        ++y;
    }
    else if (operation == '<') {
        --x;
    }
    else if (operation == '>') {
        ++x;
    }
    else if (operation == 'v') {
        --y;
    }

    if (visitedCoords.find(make_pair(x, y)) == visitedCoords.end()) {
        visitedCoords[make_pair(x, y)] = true;
        ++count;
    }
}

int day3a(string file) {
    fstream fs(file);

    int x = 0;
    int y = 0;
    map<pair<int, int>, bool> visitedCoords;
    visitedCoords[make_pair(x,y)] = true;

    int count = 1;
    char operation;
    while (fs >> operation) {
        updateSanta(operation, x, y, count, visitedCoords);
    }

    return count;
}

int day3b(string file) {
    fstream fs(file);

    int x1, x2 = 0;
    int y1, y2 = 0;
    map<pair<int, int>, bool> visitedCoords;
    visitedCoords[make_pair(x1,y1)] = true;

    int count = 1;
    char operation;
    while (fs >> operation) {
        updateSanta(operation, x1, y1, count, visitedCoords);
        fs >> operation;
        updateSanta(operation, x2, y2, count, visitedCoords);
    }

    return count;
}

int main() {
//    cout << day3a("../Resources/input.txt") << endl;
    cout << day3b("../Resources/input.txt") << endl;

}