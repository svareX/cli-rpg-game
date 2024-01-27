#ifndef GAMERPG_INVENTORY_H
#define GAMERPG_INVENTORY_H

#include <vector>
#include "Item.h"
#include "Weapon.h"
#include "Shield.h"
#include "Potion.h"
#include "Player.h"

using namespace std;
class Player;

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

    void equipShield(Shield* shield);

    void equipWeapon(Weapon* weapon);

    void usePotion(Potion* potion, Player* player);

private:
    Weapon* equippedWeapon;
    Shield* equippedShield;
    Potion* equippedPotion;

    void equipPotion(Potion* potion);
};

#endif // GAMERPG_INVENTORY_H
