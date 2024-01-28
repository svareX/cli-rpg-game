#include <iostream>
#include "../include/Item.h"
#include "../include/Shield.h"
using namespace std;

Shield::Shield() : Item() {
    this->m_damage = 0;
}

Shield::Shield(std::string name, float damage) : Item(name) {
    this->m_damage = damage;
}

float Shield::getDamage() {
    return m_damage;
}

void Shield::printInfo(){
    std::cout << endl << getName();
    std::cout << endl << getQuality();
    std::cout << endl << getDamage();
    std::cout << endl << getType();
}

Shield::~Shield() {
    std::cout << std::endl << "Shield has been destroyed.";
}