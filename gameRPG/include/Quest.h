//
// Created by temel on 24.11.2023.
//

#ifndef GAMERPG_QUEST_H
#define GAMERPG_QUEST_H

#include <iostream>
#include <vector>
#include "Map.h"

using namespace std;

struct QuestGiven{
    string task;
    float goldAmount;
};

class Map;


class Quest{
    int questGiverX, questGiverY;
    QuestGiven questInfo;
    Map& map;
    vector<Quest*> allQuests;
public:
    Quest(Map& gameMap);
    void display();
    void addQuest(Quest* quest);
    int getQuestGiverX();
    int getQuestGiverY();
    QuestGiven getQuestInfo();
};
#endif //GAMERPG_QUEST_H
