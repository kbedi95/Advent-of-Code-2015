#include <iostream>
#include <fstream>
#include "md5.h"
using namespace std;


int day4a(string file) {
    fstream fs(file);
    string secret;
    fs >> secret;

    int res = 1;

    while (md5(secret + to_string(res)).substr(0,5) != "00000") {
        ++res;
    }

    return res;
}

int day4b(string file) {
    fstream fs(file);
    string secret;
    fs >> secret;

    int res = 1;

    while (md5(secret + to_string(res)).substr(0,6) != "000000") {
        ++res;
    }

    return res;
}

int main() {
    cout << day4a("../Resources/input.txt") << endl;
//    cout << day4b("../Resources/input.txt") << endl;



}