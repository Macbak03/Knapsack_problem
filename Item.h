#pragma once

#include <map>
#include <string>
#include <functional>
#include <memory>

enum ItemName {
    pelt, tusk, bone, scales, skull, claw, bowl, cup, ruby, diamond
};

class Item {
private:
    std::map<ItemName, std::string> nameToString = {{pelt,    "pelt"},
                                                    {tusk,    "tusk"},
                                                    {bone,    "bone"},
                                                    {scales,  "scales"},
                                                    {skull,   "skull"},
                                                    {claw,    "claw"},
                                                    {bowl,    "bowl"},
                                                    {cup,     "cup"},
                                                    {ruby,    "ruby"},
                                                    {diamond, "diamond"}};
protected:
    int prize;
    int weight;

    //int itemNumber;
public:
    ItemName name;
    //Item(int prizeRange, int weightRange);
    std::string enumToString(ItemName name);
    std::unique_ptr<Item> createItem(int itemId);
    int getPrize() const;
    int getWeight() const;
};

