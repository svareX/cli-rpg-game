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
    int playerX, playerY;
    Map& map;
public:
    Player(Map& gameMap);
    void movePlayer(char move);
    void attackSequence();
    int attack(int eHealth, int hStrength);

    void setPlayerX(int x);
    void setPlayerY(int y);
    void setHealth(int h);

    int getPlayerX();
    int getPlayerY();
    int getHealth();
    int getStrength();
};
#endif //GAMERPG_PLAYER_H
