#include <fstream>
#include <iostream>
#include <sstream>
#include "Algorithm.h"
#include "map"

using namespace std;

const string Algorithm::argumentBruteForce = "--BruteForce";
const string Algorithm::argumentDynamicProgramming = "--DynamicProgramming";

Algorithm::Algorithm(const string &fileName) {
    maxItemsValue = 0;
    weightUsed = 0;
    capacity = 0;
    itemsCount = 0;
    ifstream file(fileName);
    if (!file) {
        cerr << "Error opening file." << endl;
        return;
    }

    file >> capacity;
    file >> itemsCount;

    values = vector<int>(itemsCount);
    weights = vector<int>(itemsCount);
    names = vector<string>(itemsCount);

    for (int i = 0; i < itemsCount; ++i) {
        file >> values[i] >> weights[i] >> names[i];
    }

    file.close();
}

void Algorithm::printSolution() {
    map<string, int> nameCounts;

    for (int item: solution) {
        nameCounts[names[item]]++;
    }

    int allItemsValue = 0;
    for (int value: values) {
        allItemsValue += value;
    }

    cout << "Value in items: " << maxItemsValue << "/" << allItemsValue << " Taken knapsack space: " << weightUsed
         << "/" << capacity << endl;
    cout << "Items in knapsack: ";

    for (auto &item: nameCounts) {
        cout << item.second << "x " << item.first << " ";
    }
    cout << endl;
}
