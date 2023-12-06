#include <iostream>
#include "../include/Inventory.h"
using namespace std;

void Inventory::addItem(Item* item) {
    if (!containsItem(item)) {
        ItemsInInventory.push_back(item);
        cout << "Added " << item->getName() << " to the inventory." << endl;
    } else {
        cout << item->getName() << " is already in the inventory." << endl;
    }
}

bool Inventory::containsItem(Item* item) {
    for (const auto& inventoryItem : ItemsInInventory) {
        if (inventoryItem->getName() == item->getName()) {
            return true;
        }
    }
    return false;
}

void Inventory::equipItem(Item* item) {
    if(item->getType()=="Weapon")
    {
        equipWeapon(dynamic_cast<Weapon*>(item));
    }
    else if(item->getType()=="Shield")
    {
        equipShield(dynamic_cast<Shield*>(item));
    }
    else if(item->getType()=="Potion"){
        equipPotion(dynamic_cast<Potion*>(item));
    }
    else{
        cout << "Cannot equip item of unknown type." << endl;
    }
}

void Inventory::equipWeapon(Weapon* weapon) {
    equippedWeapon = weapon;
    weapon->setIsEquipped();
}

void Inventory::equipShield(Shield* shield) {
    equippedShield = shield;
    shield->setIsEquipped();
}

void Inventory::equipPotion(Potion* potion) {
    equippedPotion = potion;
    potion->setIsEquipped();
}

Weapon* Inventory::getEquippedWeapon() {
    return equippedWeapon;
}

Shield* Inventory::getEquippedShield() {
    return equippedShield;
}

Potion* Inventory::getEquippedPotion() {
    return equippedPotion;
}

