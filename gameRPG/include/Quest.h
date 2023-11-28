//
// Created by temel on 24.11.2023.
//

#ifndef GAMERPG_QUEST_H
#define GAMERPG_QUEST_H

#include <iostream>
#include <vector>
#include "Map.h"

using namespace std;

enum Status{
    NotAccepted,
    Pending,
    Completed
};

struct QuestGiven{
    string task;
    float goldAmount;
    Status status;
};

class Map;
class Player;


class Quest{
    int questGiverX, questGiverY;
    QuestGiven questInfo;
    Map& map;
    vector<Quest*> allQuests;
public:
    Quest(Map& gameMap);
    void display(Player* player);
    void addQuest(Quest* quest);
    int getQuestGiverX();
    int getQuestGiverY();
    QuestGiven getQuestInfo();
    void setQuestStatus(enum Status Stat);
    string getQuestStatus();
};
#endif //GAMERPG_QUEST_H
