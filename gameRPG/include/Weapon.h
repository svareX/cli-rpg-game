//
// Created by stepa on 27.11.2023.
//

#ifndef GAMERPG_WEAPON_H
#define GAMERPG_WEAPON_H

#include <string>
#include "Item.h"

class Weapon : public Item {
    std::string m_name;
    float m_damage;
    float m_critical_chance;
    int m_durability;

public:
    Weapon();
    Weapon(std::string name, float damage, float critical_chance, int durability);
    void printInfo();
};

#endif //GAMERPG_WEAPON_H
