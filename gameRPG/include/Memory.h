//
// Created by stepa on 28.01.2024.
//

#ifndef GAMERPG_MEMORY_H
#define GAMERPG_MEMORY_H

#include "GameEngine.h"

class Memory {
public:
    static Memory& getInstance();

    bool containsData();
    void saveData(GameEngine* gameEngine);
    GameEngine* loadData();

private:
    Memory();
    ~Memory();

    static Memory m_instance;
    GameEngine* m_engine;

};

#endif //GAMERPG_MEMORY_H
