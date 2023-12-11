//
// Created by temel on 23.11.2023.
//

#ifndef GAMERPG_MAP_H
#define GAMERPG_MAP_H

#include <vector>
#include "Player.h"
#include "Quest.h"
#include "Inventory.h"
#include "Merchant.h"
using namespace std;
const int map_size = 10;

class Player;
class Quest;
class Merchant;

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
    vector <ItemInfo> questItems;

    void setPlayerX(int x);
    void setPlayerY(int y);
    void setPlayerCoordinates(int x, int y);

    void displayMap();
    void movePlayer(char move);
    vector<vector<char>> gameMap;
    vector<Quest*> quests;
    Merchant* shop;
    void addQuestToMap(Quest* quest);
};

#endif //GAMERPG_MAP_H
