//
// Created by temel on 23.11.2023.
//

#ifndef GAMERPG_PLAYER_H
#define GAMERPG_PLAYER_H

#include "Map.h"
#include "Inventory.h"
#include "Enemy.h"

class Quest;
class Map;

class Player {
private:
    int m_health, m_strength;
    float m_goldAmount;
    Map* m_map;
public:
    std::vector<Quest*> questList;
    Inventory* inventory;
    Player();
    
    Player(Map* gameMap);
    void movePlayer(char move);
    void setHealth(int h);
    void removeHealth(int h);
    void acceptQuest(Quest* quest);
    void printQuestList();
    void setPlayerX(int x);
    void setPlayerY(int y);
    int getHealth();
    int getDamage();
    float getGoldAmount();
    void setGoldAmount(float gold);
    void setMap(Map* gameMap);
};
#endif //GAMERPG_PLAYER_H
