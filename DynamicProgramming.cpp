#include "DynamicProgramming.h"

using namespace std;

void DynamicProgramming::findKnapsackProblemSolution() {
    std::vector<std::vector<int>> dp(itemsCount + 1, std::vector<int>(capacity + 1, 0));

    for (int i = 1; i <= itemsCount; ++i) {
        for (int w = 0; w <= capacity; ++w) {
            if (weights[i - 1] <= w) {
                dp[i][w] = std::max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    maxItemsValue = dp[itemsCount][capacity];

    int remainingCapacity = capacity;
    for (int i = itemsCount; i > 0; --i) {
        if (dp[i][remainingCapacity] != dp[i - 1][remainingCapacity]) {
            solution.push_back(i - 1);
            remainingCapacity -= weights[i - 1];
        }
    }

    weightUsed = capacity - remainingCapacity; 
    printSolution();
}

