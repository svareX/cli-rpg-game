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
    currentLevel = 1;
    levelCompleted = false;
    this->m_size = 5;
    this->setPlayerX(0);
    this->setPlayerY(0);
    for(int i = 0; i < m_size; i++){
        vector<char> row(m_size, '.');
        m_gameMap.push_back(row);
    }
    this->spawnRandomObjects(5);
    this->spawnEnemies(1);
}

void Map::resetMap() {
    m_gameMap.clear();
    m_enemies.clear();
    m_quests.clear();
    //TODO need to redo this to avoid code duplication
    for (int i = 0; i < m_size; i++) {
        vector<char> row(m_size, '.');
        m_gameMap.push_back(row);
    }
    setPlayerX(0);
    setPlayerY(0);
    spawnRandomObjects(5);
    spawnEnemies(2 * currentLevel);
    //TODO fix err 139
    //spawnQuests(currentLevel);
}


//TODO fix this
void Map::spawnQuests(int level) {
    for (int i = 0; i < 2 * level; i++) {
        Quest* newQuest = new Quest(this);
        m_gameMap[newQuest->getQuestGiverY()][newQuest->getQuestGiverX()] = 'Q';
        m_quests.push_back(newQuest);
    }
}

void Map::nextLevel() {
    if (currentLevel < totalLevels) {
        currentLevel++;
        resetMap();
        levelCompleted = false;
    } else {
        cout << "You finished all levels, congratulations!" << endl;
    }
}

void Map::removeDefeatedEnemies() {
    m_enemies.erase(std::remove_if(m_enemies.begin(), m_enemies.end(),
   [](Enemy* enemy) { return enemy->getHealth() <= 0; }),
    m_enemies.end());
}

void Map::checkLevelCompletion() {
    removeDefeatedEnemies();
    if (m_enemies.empty() && !levelCompleted) {
        levelCompleted = true;
        //TODO try to find a better way to do this
        m_gameMap[m_size - 1][m_size - 1] = 'L';
    } else {
        cout << "Enemies remaining: " << m_enemies.size() << endl;
    }

    displayMap();
}

void Map::attemptLevelTransition(int x, int y) {
    if (levelCompleted && x == m_size - 1 && y == m_size - 1) {
        nextLevel();
    }
}


void Map::spawnRandomObjects(int objNumber) {
    for (int i = 0; i < objNumber; ++i) {
        int x = rand() % m_size;
        int y = rand() % m_size;

        while (m_gameMap[x][y] != '.' || (x == getPlayerX() && y == getPlayerX())) {
            x = rand() % m_size;
            y = rand() % m_size;
        }
        m_gameMap[x][y] = '|';
    }
}

void Map::changeMap(int x, int y, char z) {
    if (x >= 0 && x < m_size && y >= 0 && y < m_size) {
        if(!(x == getPlayerX() && y == getPlayerY())){
            m_gameMap[x][y] = z;
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
        } while (m_gameMap[x][y] != '.');

        Enemy* enemy = new Enemy(rand()%11+40, rand()%11+5, x, y);
        m_enemies.push_back(enemy);
        m_gameMap[x][y] = 'E';
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
    char mapChar = m_gameMap[getPlayerY()][getPlayerX()];
    if (mapChar == 'Q' || mapChar == 'q'){
        for (auto quest : m_quests){
            if (quest->getQuestGiverX() == getPlayerX() && quest->getQuestGiverY() == getPlayerY()){
                quest->display(m_player);
            }
        }
    }
    if (mapChar == 'I'){
        for (auto itemInfo : m_questItems){
            if (itemInfo.m_itemX == getPlayerX() && itemInfo.m_itemY == getPlayerY()){
                m_player->inventory->addItem(itemInfo.m_item);
                m_gameMap[getPlayerY()][getPlayerX()] = '.';
            }
        }
    }
    if (mapChar == 'M'){
        m_shop->displayShop();
    }
    if (mapChar == 'E'){
        throw EnemyException();
    }
    system("CLS");
}


void Map::addQuestToMap(Quest* quest){
    m_quests.push_back(quest);
    m_gameMap[quest->getQuestGiverY()][quest->getQuestGiverX()] = 'Q';
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
                cout << setw(2) << m_gameMap[i][j];
            }
        }
        cout << endl;
    }
}

void Map::movePlayer(char move) {
    if(!(getPlayer()->getHealth() <= 0)){
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
    }
    else{
        std::cerr << "Player is dead, you can't move while you are dead" << std::endl;
        //TODO break the program when this happens
    }
    checkCollision();
    checkLevelCompletion();
    attemptLevelTransition(getPlayerX(), getPlayerY());
    system("CLS");
}
int Map::getSize() {
    return m_size;
}

Player* Map::getPlayer() {
    return m_player;
}

void Map::setPlayer(Player* player) {
    this->m_player = player;
}
