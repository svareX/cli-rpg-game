//
// Created by temel on 23.11.2023.
//

#ifndef GAMERPG_ENEMY_H
#define GAMERPG_ENEMY_H


#include <iostream>
#include "Map.h"

using namespace std;
class Enemy{
private:
    int health;
    int enemyX, enemyY;

public:
    Enemy(int h){
        health = h;
        enemyX = rand() % map_size + 1;
        enemyY = rand() % map_size + 0;
    }
    int getHealth(){return health;}
    int getEnemyX(){return enemyX;}
    int getEnemyY(){return enemyY;}

};

#endif //GAMERPG_ENEMY_H
