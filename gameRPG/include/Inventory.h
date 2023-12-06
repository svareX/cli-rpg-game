//
// Created by filip on 04.12.2023.
//

#ifndef GAMERPG_INVENTORY_H
#define GAMERPG_INVENTORY_H

#include <vector>
#include "Item.h"
#include "Weapon.h"
#include "Shield.h"
#include "Potion.h"

using namespace std;
class Inventory {
public:
    Inventory();
    void addItem(Item*  Item);
    void getEquippedWeapon();
    void getEquippedShield();
    void getEquippedPotion();
    bool containsItem(Item* Item);
    vector<Item*> ItemsInInventory;
};
#endif //GAMERPG_INVENTORY_H
