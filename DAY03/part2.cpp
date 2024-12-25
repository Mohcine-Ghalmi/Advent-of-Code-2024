#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <regex>

using namespace std;

int mul(int a, int b) {
    return a * b;
}

int extractAndMultiply(const string& line) {
    bool isEnabled = true;
    regex mulRegex(R"(mul\((\d+),(\d+)\))");
    regex doRegex(R"(do\(\))");
    regex dontRegex(R"(don't\(\))");
    smatch match;
    int sum = 0;
    string::const_iterator searchStart(line.cbegin());
    while (searchStart != line.cend()) {
        if (regex_search(searchStart, line.cend(), match, doRegex)) {                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       
            isEnabled = true;
            searchStart = match.suffix().first;
        } else if (regex_search(searchStart, line.cend(), match, dontRegex)) {
            isEnabled = false;
            searchStart = match.suffix().first;
        }
        if (regex_search(searchStart, line.cend(), match, mulRegex)) {
            if (isEnabled) {
                int a = stoi(match[1]);
                int b = stoi(match[2]);
                cout << "A = " << a << ", B = " << b << " -> " << a * b << endl;
                sum += mul(a, b);
            }
            searchStart = match.suffix().first;
        } else {
            ++searchStart;
        }
    }
    return sum;
}

int main(void) {
    ifstream inputFile("test.txt");
    string line;
    
    int totalSum = 0;
    while (getline(inputFile, line))
        totalSum += extractAndMultiply(line);
    
    cout << "sum: " << totalSum << endl;
    return 0;
}

