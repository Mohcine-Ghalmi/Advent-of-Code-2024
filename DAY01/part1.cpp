#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int calculateTotalDistance(std::vector<int>& leftList, std::vector<int>& rightList) {
    std::sort(leftList.begin(), leftList.end());
    std::sort(rightList.begin(), rightList.end());

    int totalDistance = 0;
    for (size_t i = 0; i < leftList.size(); ++i) {
        totalDistance += std::abs(leftList[i] - rightList[i]);
    }

    return totalDistance;
}

int main(void) {
    ifstream inputFile("test1.txt");
    string line;
    vector<int> A, B;

    while (getline(inputFile, line)) {
        istringstream values(line);
        double valA, valB;
        values >> valA >> valB;
        A.push_back(valA);
        B.push_back(valB);
    }
    
    cout << calculateTotalDistance(A, B) << endl;
    return (0);
}