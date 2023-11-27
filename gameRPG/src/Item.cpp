//
// Created by stepa on 27.11.2023.
//
#include <string>
#include "../include/Item.h"

using namespace std;

Item::Item() {
    this->m_quality = Quality::common;
    this->m_name = "Item";
}
Item::Item(string name) {
    this->m_quality = Quality::common;
    this->m_name = name;
}
Item::Item(string name, Quality quality) {
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
