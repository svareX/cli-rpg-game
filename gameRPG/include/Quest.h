//
// Created by temel on 24.11.2023.
//

#ifndef GAMERPG_QUEST_H
#define GAMERPG_QUEST_H

#include <iostream>
#include <vector>
#include "Map.h"
#include "Item.h"

using namespace std;

enum Status{
    NotAccepted,
    Pending,
    Completed
};

struct QuestGiven{
    string task;
    Item* itemRequired;
    float goldAmount;
    Status status;
    float itemX;
    float itemY;
};

class Map;
class Player;


class Quest{
    int m_questGiverX, m_questGiverY;
    QuestGiven m_questInfo;
    Map* m_map;
    vector<Quest*> m_allQuests;
public:
    void spawnQuestItem();
    void completeQuest();
    Quest(Map* gameMap);
    void display(Player* player);
    void addQuest(Quest* quest);
    int getQuestGiverX();
    int getQuestGiverY();
    QuestGiven getQuestInfo();
    void setQuestStatus(enum Status Stat);
    string getQuestStatus();
};
#endif //GAMERPG_QUEST_H
