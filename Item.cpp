#include <cstdlib>
#include "Item.h"
#include "Diamond.h"
#include "Pelt.h"
#include "Tusk.h"
#include "Bone.h"
#include "Scales.h"
#include "Skull.h"
#include "Claw.h"
#include "Bowl.h"
#include "Cup.h"
#include "Ruby.h"

using namespace std;

/*
Item::Item(int prizeRange, int weightRange) {
    this->prize = (rand() % prizeRange) + 1;
    this->weight = (rand() % weightRange) + 1;
}
*/

int Item::getPrize() const {
    return prize;
}

int Item::getWeight() const {
    return weight;
}

std::string Item::enumToString(ItemName name) {
    return nameToString[name];
}

std::unique_ptr<Item> Item::createItem(int itemId) {
    static map<int, function<unique_ptr<Item>()>> itemMap = {
            {1, []() { return make_unique<Pelt>(); }},
            {2, []() { return make_unique<Tusk>(); }},
            {3, []() { return make_unique<Bone>(); }},
            {4, []() { return make_unique<Scales>(); }},
            {5, []() { return make_unique<Skull>(); }},
            {6, []() { return make_unique<Claw>(); }},
            {7, []() { return make_unique<Bowl>(); }},
            {8, []() { return make_unique<Cup>(); }},
            {9, []() { return make_unique<Ruby>(); }},
            {10, []() { return make_unique<Diamond>(); }}
    };

    if(itemMap.find(itemId) != itemMap.end()){
        return  itemMap[itemId]();
    }
    return nullptr;
}
