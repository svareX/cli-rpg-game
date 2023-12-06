//
// Created by stepa on 27.11.2023.
//
#include <string>
#include "../include/Item.h"

using namespace std;

Item::Item() {
    this->m_quality = Quality::common;
    this->m_is_equipped = false;
    this->m_name = "Item";
}
Item::Item(string name) : Item() {
    this->m_name = name;
}
Item::Item(string name, int quality) : Item() {
    this->m_quality = quality;
    this->m_name = name;
}
Item::Item(string name, Quality quality) : Item() {
    this->m_quality = quality;
    this->m_name = name;
}

std::string Item::getName() {
    return this->m_name;
}

std::string Item::getQuality() {
    std::string quality = "";
    if (this->m_quality == 0) {
        quality = "Common";
    } else if (this->m_quality == 1) {
        quality = "Rare";
    } else {
        quality = "Epic";
    }
    return quality;
}
std::string Item::getType() {
    std::string type = "";
    if (this->m_type == 0) {
        type = "Weapon";
    } else if (this->m_type == 1) {
        type = "Shield";
    } else {
        type = "Quest";
    }
    return type;
}

bool Item::getIsEquipped() {
    return m_is_equipped;
}

void Item::setIsEquipped() {
    this->m_is_equipped = true;
}
