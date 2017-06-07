#include <iostream>
#include <fstream>
#include <unordered_set>
#include <map>
using namespace std;

bool isNiceA(string word) {
    unordered_set<char> vowels = { 'a', 'e', 'i', 'o', 'u'};
    unordered_set<string> disallowed = { "ab", "cd", "pq", "xy" };

    bool twiceInRowLetter = false;
    int numVowels = 0;

    int len = word.size();
    for (int i = 0; i < len; ++i) {
        if (i < len - 1 && disallowed.find(word.substr(i, 2)) != disallowed.end()) {
            return false;
        }
        if (vowels.find(word[i]) != vowels.end()) {
            ++numVowels;
        }
        if (i < len - 1 && word[i] == word[i + 1]) {
            twiceInRowLetter = true;
        }
    }

    return (numVowels >= 3) && twiceInRowLetter;
}

int day5a(string file) {
    fstream fs(file);
    string word;
    int total;
    while (fs >> word) {
        if (isNiceA(word)) {
            ++total;
        }
    }

    return total;
}

bool isNiceB(string word) {
    map<string, int> visitedPairs;

    bool skipOneRepeatLetter = false;
    bool repeatingPair = false;

    int len = word.size();
    for (int i = 0; i < len; ++i) {

        if (i < len - 1) {
            if (visitedPairs.find(word.substr(i, 2)) != visitedPairs.end() &&
                visitedPairs[word.substr(i, 2)] <= i - 2) {
                repeatingPair = true;
            } else {
                visitedPairs[word.substr(i, 2)] = i;
            }
        }

        if (i < len - 2 && word[i] == word[i + 2]) {
            skipOneRepeatLetter = true;
        }
    }

    return skipOneRepeatLetter && repeatingPair;
}

int day5b(string file) {
    fstream fs(file);
    string word;
    int total;
    while (fs >> word) {
        if (isNiceB(word)) {
            ++total;
        }
    }

    return total;
}



int main() {
    cout << day5a("../Resources/input.txt") << endl;
    cout << day5b("../Resources/input.txt") << endl;

}