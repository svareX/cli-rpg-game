
#include <iostream>
#include "../include/Item.h"
#include "../include/Potion.h"
using namespace std;

Potion::Potion() : Item() {
    this->m_damage = 0;
    this->m_heal = 0;
}

Potion::Potion(std::string name, float damage, float heal) : Item(name) {
    this->m_damage = damage;
    this->m_heal = heal;
}

float Potion::getDamage() {
    return m_damage;
}

float Potion::getHeal() {
    return m_heal;
}
void Potion::printInfo(){
    std::cout << endl << getName();
    std::cout << endl << getQuality();
    std::cout << endl << getDamage();
    std::cout << endl << getHeal();
    std::cout << endl << getType();
}

Potion::~Potion() {
    std::cout << std::endl << "Potion has been destroyed.";
}