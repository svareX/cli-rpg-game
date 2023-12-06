//
// Created by temel on 23.11.2023.
//

#ifndef GAMERPG_PLAYER_H
#define GAMERPG_PLAYER_H

#include "Map.h"

class Map;

class Player {
private:
    int health, strength;
    Map* map;
public:
    Player();
    Player(Map* gameMap);

    int attack(int eHealth, int hStrength);
    int getHealth();
    int getStrength();
    void setHealth(int);
};
#endif //GAMERPG_PLAYER_H
