//
// Created by temel on 23.11.2023.
//

#ifndef GAMERPG_MAP_H
#define GAMERPG_MAP_H

#include <vector>
#include "Player.h"
#include "Enemy.h"
#include "Quest.h"
#include "Merchant.h"
using namespace std;
class Player;
class Quest;
class Merchant;
class Map {
    int m_playerX;
    int m_playerY;
    int m_size;
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
    Enemy findEnemy(int x, int y);
    vector<vector<char>> gameMap;
    vector<Enemy> m_enemies;
    vector<Quest*> quests;
    Merchant* shop;
    void addQuestToMap(Quest* quest);
    int getSize();
};

#endif //GAMERPG_MAP_H
