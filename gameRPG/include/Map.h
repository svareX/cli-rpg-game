//
// Created by temel on 23.11.2023.
//

#ifndef GAMERPG_MAP_H
#define GAMERPG_MAP_H

#include <vector>
#include "Player.h"
#include "Enemy.h"
#include "Quest.h"
#include "Inventory.h"
#include "Merchant.h"
using namespace std;
class Player;
class Quest;
class Merchant;

struct ItemInfo {
    Item* m_item;
    int m_itemX;
    int m_itemY;
};

class Map {
    int m_playerX;
    int m_playerY;
    int m_size;
    Player* m_player;

public:
    Map();
    void spawnRandomObjects(int objNumber);
    int getPlayerX();
    int getPlayerY();
    void changeMap(int x,int y,char z);
    void setPlayerX(int x);
    void setPlayerY(int y);
    void setPlayerCoordinates(int x, int y);
    void displayMap();
    void movePlayer(char move);
    void spawnEnemies(int enemiesNumber);
    void checkCollision();
    void attackSequence();
    Enemy* findEnemy(int x, int y);
    vector<vector<char>> m_gameMap;
    vector<Enemy*> m_enemies;
    vector<Quest*> m_quests;
    vector <ItemInfo> m_questItems;
    Merchant* m_shop;
    void addQuestToMap(Quest* quest);
    int getSize();
    Player* getPlayer();
    void setPlayer(Player* player);
};

#endif //GAMERPG_MAP_H
