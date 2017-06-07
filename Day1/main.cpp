#include <iostream>
#include <fstream>
using namespace std;

int day1a(string file) {
    ifstream fs(file);

    int floor = 0;
    char instruction;
    while (fs >> instruction) {
        if (instruction == '(') {
            ++floor;
        }
        else if (instruction == ')') {
            --floor;
        }
    }

    return floor;
}

int day1b(string file) {
    ifstream fs(file);

    int floor = 0;
    char instruction;
    int pos = 1;
    while (fs >> instruction) {
        if (instruction == '(') {
            ++floor;
        }
        else if (instruction == ')') {
            --floor;
        }
        if (floor == -1) {
            return pos;
        }
        ++pos;
    }

    return -1;
}




int main() {
//    cout << day1a("../Resources/input.txt") << endl;
    cout << day1b("../Resources/input.txt") << endl;
}