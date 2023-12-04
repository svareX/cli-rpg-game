//
// Created by temel on 24.11.2023.
//

#ifndef GAMERPG_QUEST_H
#define GAMERPG_QUEST_H

#include <iostream>
#include <vector>
#include "Item.h"
#include "Map.h"
using namespace std;

struct QuestGiven{
    std::string task;
    Item* itemRequired;
    float goldAmount;
};

class Quest{
    int questGiverX, questGiverY;
    QuestGiven quest;
    Map& map; //temporary
public:
    Quest(Map& gameMap);
    int getQuestGiverX();
    int getQuestGiverY();
};
#endif //GAMERPG_QUEST_H
