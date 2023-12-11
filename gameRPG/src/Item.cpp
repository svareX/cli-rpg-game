#include "../include/Item.h"
#include <string>

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

std::string Item::getQualityName() {
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
int Item::getQuality() {
    return m_quality;
}
std::string Item::getType() {
    std::string m_type = "";
    if (this->m_type == 0) {
        m_type = "Weapon";
    } else if (this->m_type == 1) {
        m_type = "Shield";
    }
    else if (this->m_type == 2){
        m_type = "Potion";
    }
    else {
        m_type = "Type has not been set.";
    }
    return m_type;
}

bool Item::getIsEquipped() {
    return m_is_equipped;
}

void Item::setIsEquipped() {
    this->m_is_equipped = true;
}

void Item::setQuality(int quality) {
    if (quality >= 0 && quality <= 2) {
        this->m_quality = quality;
    }
}
