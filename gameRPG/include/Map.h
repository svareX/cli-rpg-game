//
// Created by temel on 23.11.2023.
//

#ifndef GAMERPG_MAP_H
#define GAMERPG_MAP_H

#include <vector>
#include "Player.h"
#include "Quest.h"
#include "Inventory.h"
using namespace std;
const int map_size = 5;

class Player;
class Quest;

struct ItemInfo{
    Item* item;
    int itemX;
    int itemY;
};

class Map {
    int m_playerX;
    int m_playerY;

public:
    Map();

    int getPlayerX();
    int getPlayerY();
    Player* player; //temporary solution to quest->display() in movePlayer()
    vector <ItemInfo> questItemsOnGround;

    void setPlayerX(int x);
    void setPlayerY(int y);
    void setPlayerCoordinates(int x, int y);

    void displayMap();
    void movePlayer(char move);
    void setPlayer(Player* player);
    void attackSequence();
    vector<vector<char>> gameMap;
    vector<Quest*> quests;
    void addQuestToMap(Quest* quest);
};

#endif //GAMERPG_MAP_H
