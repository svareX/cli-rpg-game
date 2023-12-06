//
// Created by temel on 23.11.2023.
//
#include <iostream>
#include <vector>
#include "../include/Map.h"
#include "../include/Inventory.h"
#include "../include/Item.h"
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
void Inventory::getEquippedWeapon() {

}

void Inventory::getEquippedShield() {

}
void Inventory::getEquippedPotion() {

}


