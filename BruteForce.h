#pragma once


#include "Algorithm.h"

class BruteForce : public Algorithm {
private:
    void printSolution();
public:
    using Algorithm::Algorithm;
    void findKnapsackProblemSolution();
};
