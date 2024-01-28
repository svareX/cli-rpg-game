//
// Created by temel on 23.11.2023.
//

#ifndef GAMERPG_ENEMY_H
#define GAMERPG_ENEMY_H


#include <iostream>
#include "Player.h"

class Player;

using namespace std;
class Enemy{
private:
    int m_health, m_damage;
    int m_enemyX, m_enemyY;

public:
    //Enemy();
    //Enemy(int health, int damage);
    Enemy(int health, int damage, int x, int y);

    void setHealth(int health);
    void removeHealth(int health);

    int getHealth();
    int getDamage();
    int getEnemyX();
    int getEnemyY();

    void attack(Player* player, int difficulty);

};

#endif //GAMERPG_ENEMY_H
