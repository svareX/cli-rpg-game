//
// Created by filip on 06.12.2023.
//

#ifndef GAMERPG_POTION_H
#define GAMERPG_POTION_H
#include <string>
#include "Item.h"

class Potion : public Item {
    std::string m_name;
    float m_heal;

public:
    Potion();
    Potion(std::string name, float heal);
    int getHeal();
    void printInfo();

    ~Potion();
};
#endif //GAMERPG_POTION_H
