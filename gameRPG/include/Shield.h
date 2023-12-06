//
// Created by filip on 06.12.2023.
//

#ifndef GAMERPG_SHIELD_H
#define GAMERPG_SHIELD_H
#include <string>
#include "Item.h"

class Shield : public Item {
    std::string m_name;
    float m_damage;
    float m_heal;

public:
    Shield();
    Shield(std::string name, float damage, float heal);

    float getDamage();
    float getHeal();
    void printInfo();

    ~Shield();
};
#endif //GAMERPG_SHIELD_H
