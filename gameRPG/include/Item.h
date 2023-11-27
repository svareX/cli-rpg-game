//
// Created by temel on 24.11.2023.
//

#ifndef GAMERPG_ITEM_H
#define GAMERPG_ITEM_H

#include <string>


class Item{
    std::string m_name;
    int m_quality;
    enum Quality {
        common,
        rare,
        epic
    };

public:
    Item();
    Item(std::string name);
    Item(std::string name, Quality quality);
    virtual std::string getName();
    virtual std::string getQuality();
};

#endif //GAMERPG_ITEM_H
