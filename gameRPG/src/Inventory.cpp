#include <iostream>
#include <map>
#include "../include/Inventory.h"
#include "../include/Logger.h"
#include "../include/Player.h"
#include "../include/Item.h"
using namespace std;

Inventory::Inventory(){
    this->equippedWeapon = nullptr;
    this->equippedShield = nullptr;
}
void Inventory::addItem(Item* item) {
    system("CLS");
    if (!containsItem(item)) {
        itemsInInventory.push_back(item);
        cout << "Added " << item->getName() << " to the inventory." << endl;
        Logger::getInstance().log("[ITEM] You picked up an item: " + item->getName());
    } else {
        cout << item->getName() << " is already in the inventory." << endl;
    }
    cout << "Press ENTER to continue..." << endl;
    cin.ignore();
    cin.get();
}

bool Inventory::containsItem(Item* item) {
    for (const auto& inventoryItem : itemsInInventory) {
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
    else{
        cout << "Cannot equip item of unknown type." << endl;
    }
}

void Inventory::printItems(){
    system("CLS");
    if (equippedWeapon == nullptr){
        cout << "Equipped weapon: None" << endl;
    } else{
        cout << "Equipped weapon: " << equippedWeapon->getName() << endl;
    }

    if (equippedShield == nullptr){
        cout << "Equipped shield: None" << endl;
    } else{
        cout << "Equipped shield: " << equippedShield->getName() << endl;
    }
    cout << endl;
    if (!itemsInInventory.empty()){
        int itemNumber = 1;
        for (auto item : itemsInInventory){
            cout << itemNumber << ". " << item->getName() << endl;
            itemNumber++;
        }
    }
    else{
        cout << "Your inventory is empty." << endl;
    }
    cout << "Press ENTER to continue..." << endl;
    cin.ignore();
    cin.get();
}


void Inventory::equipWeapon(Weapon* weapon) {
    if (equippedWeapon != nullptr) {
        if (weapon->getQuality() > equippedWeapon->getQuality()) {
            itemsInInventory.push_back(equippedWeapon);
            equippedWeapon->setIsEquipped(false);
            equippedWeapon = weapon;
            equippedWeapon->setIsEquipped(true);
        } else {
            itemsInInventory.push_back(weapon);
        }
    } else {
        equippedWeapon = weapon;
        equippedWeapon->setIsEquipped(true);
    }
}


void Inventory::equipShield(Shield* shield) {
    if (equippedShield != nullptr) {
        if (shield->getQuality() > equippedShield->getQuality()) {
            itemsInInventory.push_back(equippedShield);
            equippedShield->setIsEquipped(false);

            equippedShield = shield;
            equippedShield->setIsEquipped(true);
        } else {
            itemsInInventory.push_back(shield);
        }
    } else {
        equippedShield = shield;
        equippedShield->setIsEquipped(true);
    }
}


void Inventory::usePotion(Potion* potion, Player* player) {
    if (player) {
        player->addHealth(potion->getHeal());
    }
}

Weapon* Inventory::getEquippedWeapon() {
    return equippedWeapon;
}

Shield* Inventory::getEquippedShield() {
    return equippedShield;
}