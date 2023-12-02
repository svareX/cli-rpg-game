//
// Created by temel on 23.11.2023.
//

#ifndef GAMERPG_PLAYER_H
#define GAMERPG_PLAYER_H

#include "Map.h"
#include "Enemy.h"

class Map;

class Player {
private:
    int m_health, m_damage;

public:
    Player();

    void attack(Enemy* enemy);

    void setHealth(int h);
    void removeHealth(int h);

    int getHealth();
    int getDamage();
};
#endif //GAMERPG_PLAYER_H
