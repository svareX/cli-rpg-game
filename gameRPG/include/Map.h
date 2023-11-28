//
// Created by temel on 23.11.2023.
//

#ifndef GAMERPG_MAP_H
#define GAMERPG_MAP_H

#include <vector>
#include "Player.h"
#include "Quest.h"
using namespace std;
const int map_size = 5;

class Player;
class Quest;

class Map {
public:
    Map();
    void displayMap(Player* player);
    vector<vector<char>> gameMap;
    vector<Quest*> quests;
    void addQuestToMap(Quest* quest);
};

#endif //GAMERPG_MAP_H
