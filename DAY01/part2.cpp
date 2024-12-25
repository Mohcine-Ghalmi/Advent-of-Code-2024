#include <iostream>
#include <sstream>
#include <fstream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int similarityScore(vector<int> &A, vector<int> &B) {
    int sum = 0;
    for (auto val : A)
        sum += val * count(B.begin(), B.end(), val);
    return sum;

}

int main(void) {
    ifstream inputFile("test2.txt");
    string line;
    vector<int> A, B;

    while (getline(inputFile, line)) {
        istringstream values(line);
        double valA, valB;
        values >> valA >> valB;
        A.push_back(valA);
        B.push_back(valB);
    }
    
    cout << similarityScore(A, B) << endl;
    return (0);
}