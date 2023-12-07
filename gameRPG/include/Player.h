//
// Created by temel on 23.11.2023.
//

#ifndef GAMERPG_PLAYER_H
#define GAMERPG_PLAYER_H

#include "Map.h"
#include "Inventory.h"

class Quest;
class Map;

class Player {
private:
    int health, strength;
    Map* map;
public:
    std::vector<Quest*> questList;
    Inventory* inventory;
    Player();
    Player(Map* gameMap);
    void movePlayer(char move);
    int attack(int eHealth, int hStrength);
    void acceptQuest(Quest* quest);
    void printQuestList();
    void setPlayerX(int x);
    void setPlayerY(int y);
    void setHealth(int h);
    int getHealth();
    int getStrength();
};
#endif //GAMERPG_PLAYER_H
