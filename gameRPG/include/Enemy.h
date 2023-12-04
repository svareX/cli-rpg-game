//
// Created by temel on 23.11.2023.
//

#ifndef GAMERPG_ENEMY_H
#define GAMERPG_ENEMY_H


#include <iostream>
using namespace std;
class Enemy{
private:
    int health;
    int enemyX, enemyY;
public:
    Enemy(int h);
    int getHealth();
    int getEnemyX();
    int getEnemyY();
};

#endif //GAMERPG_ENEMY_H
