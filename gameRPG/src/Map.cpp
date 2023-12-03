//
// Created by temel on 23.11.2023.
//
#include <iostream>
#include <vector>
#include <iomanip>
#include "../include/Map.h"
#include "../include/Player.h"
using namespace std;
Map::Map(){
    this->setPlayerX(1);
    this->setPlayerY(1);
    for(int i = 0; i < map_size; i++){
        vector<char> row(map_size, '.');
        gameMap.push_back(row);
    }
    gameMap[3][2] = 'G';
    gameMap[0][4] = 'X';
}

void Map::spawnRandomObjects(int objNumber) {
    for (int i = 0; i < objNumber; ++i) {
        int x = rand() % map_size;
        int y = rand() % map_size;

        while (gameMap[x][y] != '.' || (x == getPlayerX() && y == getPlayerX())) {
            x = rand() % map_size;
            y = rand() % map_size;
        }
        gameMap[x][y] = 'O';
    }
}

void Map::changeMap(int x, int y, char z) {
    if (x >= 0 && x < map_size && y >= 0 && y < map_size) {
        if(!(x == getPlayerX() && y == getPlayerY())){
        gameMap[x][y] = z;
        }
        else{
         cerr << "You can't put object where the player is standing";
        }
    }
    else {
        cout << "you can't change fields outside the map" << endl;
    }
}


Enemy Map::findEnemy(int x, int y){
for(auto &enemy : m_enemies){
    if (x == enemy.getEnemyX() && y == enemy.getEnemyY())
        return enemy;
}
}


int Map::getPlayerX() {
    return this->m_playerX;
}
int Map::getPlayerY() {
    return this->m_playerY;
}

//TODO: Add a method that checks if you can actually set that field as the players coordinates (if theres is an enemy, structure
// or if it is just out of bounds) + negative numbers

void Map::setPlayerX(int x) {
    this->m_playerX = x;
}
void Map::setPlayerY(int y) {
    this->m_playerY = y;
}
void Map::setPlayerCoordinates(int x, int y) {
    this->m_playerX = x;
    this->m_playerY = y;
}

void Map::displayMap(){
    system("cls");
    for (int i = 0; i < map_size; i++){
        for (int j = 0; j < map_size; j++){
            if (i == getPlayerX() && j == getPlayerY()){
                cout << setw(2) << 'P';
            }
            else{
                cout << setw(2) << gameMap[i][j];
            }
        }
        cout << endl;
    }
}

void Map::movePlayer(char move) {
    switch (toupper(move)) {
        case 'W':
            if (getPlayerY() > 0) {
                setPlayerY(getPlayerY()-1);
            } else {
                cerr << "You have reached the border!" << endl;
            }
            break;
        case 'A':
            if (getPlayerX() > 0) {
                setPlayerX(getPlayerX()-1);
            } else {
                cerr << "You have reached the border!" << endl;
            }
            break;
        case 'S':
            if (getPlayerY() < map_size - 1) {
                setPlayerY(getPlayerY()+1);
            } else {
                cerr << "You have reached the border!" << endl;
            }
            break;
        case 'D':
            if (getPlayerX() < map_size - 1) {
                setPlayerX(getPlayerX()+1);
            } else {
                cerr << "You have reached the border!" << endl;
            }
            break;
    }
    if (getPlayerX() == 4 && getPlayerY() == 0) {
        //attackSequence();
    }
    system("CLS");
}
