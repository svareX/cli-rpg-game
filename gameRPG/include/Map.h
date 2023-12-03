//
// Created by temel on 23.11.2023.
//

#ifndef GAMERPG_MAP_H
#define GAMERPG_MAP_H

#include <vector>
#include "Player.h"
using namespace std;
const int map_size = 5;
class Player;

class Map {
    int m_playerX;
    int m_playerY;

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
    void attackSequence();
    vector<vector<char>> gameMap;
};

#endif //GAMERPG_MAP_H
