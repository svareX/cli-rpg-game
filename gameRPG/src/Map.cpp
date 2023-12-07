//
// Created by temel on 23.11.2023.
//
#include <iostream>
#include <vector>
#include <iomanip>
#include "../include/Map.h"
#include "../include/Inventory.h"
#include "../include/Player.h"
using namespace std;
Map::Map(){
    this->setPlayerX(0);
    this->setPlayerY(0);
    for(int i = 0; i < map_size; i++){
        vector<char> row(map_size, '.');
        gameMap.push_back(row);
    }
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
void Map::addQuestToMap(Quest* quest){
    quests.push_back(quest);
    gameMap[quest->getQuestGiverY()][quest->getQuestGiverX()] = 'Q';
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
        case 'L':
            player->printQuestList();
            break;
        case 'I':
            player->inventory->printItems();
            break;
    }
    //TODO : Create checkCollision() function instead of these if statements
    if (getPlayerX() == 4 && getPlayerY() == 0) {
        attackSequence();
    }
    char mapChar = gameMap[getPlayerY()][getPlayerX()];
    if (mapChar == 'Q' || mapChar == 'q'){
        for (auto quest : quests){
            if (quest->getQuestGiverX() == getPlayerX() && quest->getQuestGiverY() == getPlayerY()){
                quest->display(player);
            }
        }
    }
    if (mapChar == 'I'){
        for (auto itemInfo : questItems){
            if (itemInfo.itemX == getPlayerX() && itemInfo.itemY == getPlayerY()){
                player->inventory->addItem(itemInfo.item);
                gameMap[getPlayerY()][getPlayerX()] = '.';
            }
        }
    }
    system("CLS");
}
void Map::attackSequence() {
    system("cls");
    char choice;
    int hHealth = 10;
    int hStrength = 2;
    int eHealth = 10;
    char dump;
    cout << "You have encountered an enemy. Do you wanna fight? ";
    cin >> choice;
    if (toupper(choice) == 'Q') {
        return;
    } else {
        while (hHealth != 0 && eHealth != 0) {
            system("cls");
            cout << "Your Health: " << hHealth << " | Enemy Health: " << eHealth << endl;
            cout << "What do you wanna do? (A - Attack): ";
            cin >> choice;
            switch (toupper(choice)) {
                case 'A':
                    //eHealth = attack(eHealth, hStrength);
                    break;
            }
        }
        cout << "Enemy has been slained." << endl;
        gameMap[0][4] = '.';
        cin.ignore();
    }
}

void Map::setPlayer(Player* player){
    this->player = player;
}
