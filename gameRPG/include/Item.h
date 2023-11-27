//
// Created by temel on 24.11.2023.
//

#ifndef GAMERPG_ITEM_H
#define GAMERPG_ITEM_H

#include <string>


class Item{
    std::string m_name;

public:
    Item();
    Item(std::string name);
    virtual std::string getName();
};

#endif //GAMERPG_ITEM_H
