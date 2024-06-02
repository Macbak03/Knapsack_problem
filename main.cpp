#include <iostream>
#include <fstream>
#include "Item.h"
#include "BruteForce.h"

using namespace std;

const string fileName = "Knapsack.txt";

void generateItemsFile() {
    int itemsCount = 20;
    int capacity = 60;
    Item item;

    ofstream file(fileName);
    file << capacity << endl << itemsCount << endl;
    srand(time(nullptr));
    for (int i = 0; i < itemsCount; ++i) {
        int itemNumber = (rand() % 10) + 1;
        /*int prizeRange = 10;
        int weightRange = 4;
        Item item(prizeRange, weightRange);*/
        unique_ptr<Item> miscItem = item.createItem(itemNumber);
        string miscItemNameString = item.enumToString(miscItem->name);
        file << miscItem->getPrize() << " " << miscItem->getWeight() << " " << miscItemNameString << endl;
    }
    file.close();
}


int main() {
    //generateItemsFile();
    BruteForce bruteForce(fileName);
    bruteForce.findKnapsackProblemSolution();
    return 0;
}
