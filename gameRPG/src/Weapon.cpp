//
// Created by stepa on 27.11.2023.
//
#include <iostream>
#include "../include/Item.h"
#include "../include/Weapon.h"
using namespace std;

Weapon::Weapon() : Item() {
    this->m_damage = 0;
    this->m_critical_chance = 0;
}

Weapon::Weapon(std::string name, float damage, float critical_chance, int durability) : Item(name) {
    this->m_damage = damage;
    this->m_critical_chance = critical_chance;
}

float Weapon::getDamage() {
    return m_damage;
}

float Weapon::getCriticalChance() {
    return m_critical_chance;
}
void Weapon::printInfo(){
    std::cout << endl << getName();
    std::cout << endl << getQuality();
    std::cout << endl << getDamage();
    std::cout << endl << getCriticalChance();
}

Weapon::~Weapon() {
    std::cout << std::endl << "Sword has been destroyed.";
}