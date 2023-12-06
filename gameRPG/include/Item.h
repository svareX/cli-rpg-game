//
// Created by temel on 24.11.2023.
//

#ifndef GAMERPG_ITEM_H
#define GAMERPG_ITEM_H

#include <string>

class Item{
    std::string m_name;
    bool m_is_equipped;
    int m_quality;

public:
    enum Quality {
        common,
        rare,
        epic
    };
    enum class ItemType {
        Weapon,
        Shield,
        Quest
    };
    Item();
    Item(std::string name);
    Item(std::string name, int quality);
    Item(std::string name, Quality quality);

    virtual std::string getName();
    virtual std::string getQuality();
    virtual std::string getType();
    virtual bool getIsEquipped();

    virtual void setIsEquipped();
};

#endif //GAMERPG_ITEM_H
