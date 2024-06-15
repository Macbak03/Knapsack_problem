#pragma once
#include <vector>
#include <string>

class Algorithm {
protected:
    std::vector<int> weights;
    std::vector<int> values;
    std::vector<std::string> names;
    int capacity;
    int itemsCount;
    int maxItemsValue;
    int weightUsed;
    std::vector<int> solution;

public:
    const static std::string argumentBruteForce;
    const static std::string argumentDynamicProgramming;
    explicit Algorithm(const std::string& fileName);
    void printSolution();
};
