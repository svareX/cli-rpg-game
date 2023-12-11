#include <iostream>
#include <vector>
#include <iomanip>
#include "../include/Map.h"
#include "../include/Inventory.h"
#include "../include/Player.h"
#include "../include/Quest.h"
#include "../include/Enemy.h"
#include "../include/exceptions/EnemyException.h"

using namespace std;



Map::Map(){
    this->m_size = 10;
    this->setPlayerX(0);
    this->setPlayerY(0);
    for(int i = 0; i < m_size; i++){
        vector<char> row(m_size, '.');
        gameMap.push_back(row);
    }
    this->spawnRandomObjects(5);
    this->spawnEnemies(3);
}

void Map::spawnRandomObjects(int objNumber) {
    for (int i = 0; i < objNumber; ++i) {
        int x = rand() % m_size;
        int y = rand() % m_size;

        while (gameMap[x][y] != '.' || (x == getPlayerX() && y == getPlayerX())) {
            x = rand() % m_size;
            y = rand() % m_size;
        }
        gameMap[x][y] = '|';
    }
}

void Map::changeMap(int x, int y, char z) {
    if (x >= 0 && x < m_size && y >= 0 && y < m_size) {
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




void Map::spawnEnemies(int numEnemies) {
    for (int i = 0; i < numEnemies; i++) {
        int x, y;
        do {
            x = std::rand() % m_size;
            y = std::rand() % m_size;
        } while (gameMap[x][y] != '.');

        Enemy* enemy = new Enemy(50, 10, x, y);
        m_enemies.push_back(enemy);
        gameMap[x][y] = 'E';
    }
}

Enemy* Map::findEnemy(int x, int y){
    for(auto enemy : m_enemies){
        if (x == enemy->getEnemyY() && y == enemy->getEnemyX())
            return enemy;
    }
    return nullptr;
}

void Map::checkCollision(){
    char mapChar = gameMap[getPlayerY()][getPlayerX()];
    if (mapChar == 'Q' || mapChar == 'q'){
        for (auto quest : quests){
            if (quest->getQuestGiverX() == getPlayerX() && quest->getQuestGiverY() == getPlayerY()){
                quest->display(m_player);
            }
        }
    }
    if (mapChar == 'I'){
        for (auto itemInfo : questItems){
            if (itemInfo.itemX == getPlayerX() && itemInfo.itemY == getPlayerY()){
                m_player->inventory->addItem(itemInfo.item);
                gameMap[getPlayerY()][getPlayerX()] = '.';
            }
        }
    }
    if (mapChar == 'M'){
        shop->displayShop();
    }
    system("CLS");
}


void Map::addQuestToMap(Quest* quest){
    quests.push_back(quest);
    gameMap[quest->getQuestGiverY()][quest->getQuestGiverX()] = 'Q';
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
    for (int i = 0; i < m_size; i++){
        for (int j = 0; j < m_size; j++){
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
    checkCollision();
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
            if (getPlayerY() < m_size - 1) {
                setPlayerY(getPlayerY()+1);
            } else {
                cerr << "You have reached the border!" << endl;
            }
            break;
        case 'D':
            if (getPlayerX() < m_size - 1) {
                setPlayerX(getPlayerX()+1);
            } else {
                cerr << "You have reached the border!" << endl;
            }
            break;
        case 'L':
            getPlayer()->printQuestList();
            break;
        case 'I':
            getPlayer()->inventory->printItems();
            break;
    }
    if (getPlayerX() == 4 && getPlayerY() == 0) {
        //attackSequence();
    }
    system("CLS");
}
/*
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
 */
int Map::getSize() {
    return m_size;
}

Player* Map::getPlayer() {
    return m_player;
}

void Map::setPlayer(Player* player) {
    this->m_player = player;
}
