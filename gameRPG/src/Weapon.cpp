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
    this->m_durability = 0;
}

Weapon::Weapon(std::string name, float damage, float critical_chance, int durability) : Item(name) {
    this->m_damage = damage;
    this->m_critical_chance = critical_chance;
    this->m_durability = durability;
}

void Weapon::printInfo(){
    std::cout << endl << this->m_name;
    std::cout << endl << this->m_damage;
    std::cout << endl << this->m_critical_chance;
    std::cout << endl << this->m_durability;
}