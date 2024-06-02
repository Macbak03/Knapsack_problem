#include <valarray>
#include "BruteForce.h"

using namespace std;

void BruteForce::findKnapsackProblemSolution() {
    long long totalCombinations = pow(2, itemsCount);

    for (unsigned long long combinationNumber = 1; combinationNumber < totalCombinations; ++combinationNumber) {
        int currentWeight = 0;
        int currentValue = 0;

        for (int i = 0; i < itemsCount; ++i) {
            if (combinationNumber & (1 << i)) {
                currentWeight += weights[i];
                currentValue += values[i];
            }
        }

        if (currentWeight <= capacity && currentValue > maxItemsValue) {
            maxItemsValue = currentValue;
            weightUsed = currentWeight;
            solution.clear();
            for (int i = 0; i < itemsCount; ++i) {
                if (combinationNumber & (1 << i)) {
                    solution.push_back(i);
                }
            }
        }

    }
    printSolution();
}
