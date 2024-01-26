#include <iostream>
#include "../include/Inventory.h"
#include "../include/Logger.h"
using namespace std;

Inventory::Inventory(){
    this->equippedWeapon = nullptr;
    this->equippedShield = nullptr;
    this->equippedPotion = nullptr;
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
    else if(item->getType()=="Potion"){
        equipPotion(dynamic_cast<Potion*>(item));
    }
    else{
        cout << "Cannot equip item of unknown type." << endl;
    }
}

void Inventory::printItems(){
    system("CLS");
    if (!itemsInInventory.empty()){
        for (auto item : itemsInInventory){
            cout << item->getName() << endl;
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