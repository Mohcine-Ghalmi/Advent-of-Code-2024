#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>
#include <fstream>

using namespace std;

bool isSafeReport(const vector<int>& levels) {
    auto isSafe = [](const vector<int>& lvls) {
        bool isIncreasing = lvls[1] > lvls[0];
        for (size_t i = 1; i < lvls.size(); ++i) {
            int diff = lvls[i] - lvls[i - 1];
            if (abs(diff) < 1 || abs(diff) > 3) 
                return false;
            if (isIncreasing && diff <= 0)
                return false;
            if (!isIncreasing && diff >= 0)
                return false;
        }
        return true;
    };

    if (isSafe(levels)) return true;

    for (size_t i = 0; i < levels.size(); ++i) {
        vector<int> modifiedLevels = levels;
        modifiedLevels.erase(modifiedLevels.begin() + i);
        if (isSafe(modifiedLevels)) return true;
    }

    return false;
}

int main() {
    ifstream inputFile("test.txt");
    string line;
    vector<vector<int>> reports;

    while (getline(inputFile, line)) {
        istringstream values(line);
        vector<int> report;
        int value;
        while (values >> value)
            report.push_back(value);
        reports.push_back(report);
    }

    int safeCount = 0;
    for (const auto& report : reports) {
        if (isSafeReport(report))
            safeCount++;
    }
    cout << "Number of safe reports: " << safeCount << endl;

    return 0;
}
