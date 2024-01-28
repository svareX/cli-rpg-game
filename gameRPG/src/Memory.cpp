#include "../include/Memory.h"

Memory Memory::m_instance;

Memory::Memory() {
    m_engine = nullptr;
}

Memory::~Memory() {
    m_engine = nullptr;
}

bool Memory::containsData() {
    if (m_engine == nullptr) {
        return false;
    } else {
        return true;
    }
}

void Memory::saveData(GameEngine* gameEngine) {
    m_engine = gameEngine;
}

GameEngine* Memory::loadData() {
    return m_engine;
}

Memory &Memory::getInstance() {
    return m_instance;
}

