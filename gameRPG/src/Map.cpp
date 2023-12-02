//
// Created by temel on 23.11.2023.
//
#include <iostream>
#include <vector>
#include <iomanip>
#include "../include/Map.h"
#include "../include/Player.h"
#include "../include/exceptions/BorderException.h"
#include "../include/exceptions/EnemyException.h"

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
    cout << getPlayerY() << " | " << getPlayerX() << endl;
    for (int i = 0; i < map_size; i++){
        for (int j = 0; j < map_size; j++){
            if (i == getPlayerY() && j == getPlayerX()){
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
                throw BorderException();
            }
            break;
        case 'A':
            if (getPlayerX() > 0) {
                setPlayerX(getPlayerX()-1);
            } else {
                cerr << "You have reached the border!" << endl;
                throw BorderException();
            }
            break;
        case 'S':
            if (getPlayerY() < map_size - 1) {
                setPlayerY(getPlayerY()+1);
            } else {
                cerr << "You have reached the border!" << endl;
                throw BorderException();
            }
            break;
        case 'D':
            if (getPlayerX() < map_size - 1) {
                setPlayerX(getPlayerX()+1);
            } else {
                cerr << "You have reached the border!" << endl;
                throw BorderException();
            }
            break;
    }
    //TODO: add enemy detection - not just this static solution
    if (getPlayerX() == 4 && getPlayerY() == 0) {
        throw EnemyException();
    }
    system("CLS");
}
