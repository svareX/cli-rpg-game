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
    void printItems();
    void addItem(Item* item);
    void equipItem(Item* item);
    Weapon* getEquippedWeapon();
    Shield* getEquippedShield();
    Potion* getEquippedPotion();
    bool containsItem(Item* item);
    vector<Item*> itemsInInventory;
private:
    Weapon* equippedWeapon;
    Shield* equippedShield;
    Potion* equippedPotion;

    void equipWeapon(Weapon* weapon);
    void equipShield(Shield* shield);
    void equipPotion(Potion* potion);
};

#endif // GAMERPG_INVENTORY_H
