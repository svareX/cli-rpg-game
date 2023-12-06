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
    for (const auto& item : ItemsInInventory) {
        if (item->getIsEquipped() && item->getType() == Item::ItemType::Weapon) {
            cout << "Equipped Weapon: " << item->getName() << endl;
            return;
        }
    }
    cout << "No equipped weapon found." << endl;
}

void Inventory::getEquippedShield() {
    for (const auto& item : ItemsInInventory) {
        if (item->getIsEquipped() && item->getType() == Item::ItemType::Shield) {
            cout << "Equipped Shield: " << item->getName() << endl;
            return;
        }
    }
    cout << "No equipped shield found." << endl;
}


