//
// Created by stepa on 27.11.2023.
//
#include <string>
#include "../include/Item.h"

using namespace std;

Item::Item() {
    this->m_name = "Item";
}
Item::Item(string name) {
    this->m_name = name;
}

std::string Item::getName() {
    return this->m_name;
}
