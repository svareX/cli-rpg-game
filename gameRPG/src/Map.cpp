#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include "../include/Map.h"
#include "../include/Inventory.h"
#include "../include/Player.h"
#include "../include/Quest.h"
#include "../include/Enemy.h"
#include "../include/exceptions/EnemyException.h"
#include "../include/Logger.h"
#include "../include/Memory.h"
#include "../include/exceptions/PauseGameException.h"

using namespace std;



Map::Map(){
    currentLevel = 1;
    levelCompleted = false;
    this->m_size = 10;
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
    for (int i = 0; i < m_size; i++) {
        vector<char> row(m_size, '.');
        m_gameMap.push_back(row);
    }
    setPlayerX(0);
    setPlayerY(0);
    spawnRandomObjects(5);
    spawnEnemies(2 * currentLevel);
    srand(time(NULL));
    int randX = rand() % m_size;
    int randY = rand() % m_size;
    m_gameMap[randY][randX] = 'M';
    int numberOfQuests = rand() % 5 + 1;
    for (int i = 0; i < numberOfQuests; i++) {
        Quest* newQuest = new Quest(this);
        int questGiverX = newQuest->getQuestGiverX();
        int questGiverY = newQuest->getQuestGiverY();
        if (m_gameMap[questGiverY][questGiverX] == '.') {
            addQuestToMap(newQuest);
        }
    }}

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
    if (m_enemies.empty() && m_quests.empty() && !levelCompleted) {
        levelCompleted = true;
        m_gameMap[m_size - 1][m_size - 1] = 'L';
    }
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
        } while (m_gameMap[x][y] != '.' || (x == getPlayerX() && y == getPlayerY()));

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
    cout << getPlayerY() << " | " << getPlayerX() << " || Press H for Help" << endl;
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
            if (getPlayerY() > 0 && m_gameMap[getPlayerY()-1][getPlayerX()] != '|') {
                setPlayerY(getPlayerY()-1);
            } else {
                cerr << "You have reached the border!" << endl;
                Logger::getInstance().log("[ERROR] YOU HIT A BORDER/OBSTACLE");
            }
            break;
        case 'A':
            if (getPlayerX() > 0 && m_gameMap[getPlayerY()][getPlayerX()-1] != '|') {
                setPlayerX(getPlayerX()-1);
            } else {
                cerr << "You have reached the border!" << endl;
                Logger::getInstance().log("[ERROR] YOU HIT A BORDER/OBSTACLE");
            }
            break;
        case 'S':
            if (getPlayerY() < m_size - 1 && m_gameMap[getPlayerY()+1][getPlayerX()] != '|') {
                setPlayerY(getPlayerY()+1);
            } else {
                cerr << "You have reached the border!" << endl;
                Logger::getInstance().log("[ERROR] YOU HIT A BORDER/OBSTACLE");
            }
            break;
        case 'D':
            if (getPlayerX() < m_size - 1 && m_gameMap[getPlayerY()][getPlayerX()+1] != '|') {
                setPlayerX(getPlayerX()+1);
            } else {
                cerr << "You have reached the border!" << endl;
                Logger::getInstance().log("[ERROR] YOU HIT A BORDER/OBSTACLE");
            }
            break;
        case 'L':
            getPlayer()->printQuestList();
            break;
        case 'P':
            throw PauseGameException();
            break;
        case 'I':
            getPlayer()->inventory->printItems();
            if (!getPlayer()->inventory->itemsInInventory.empty()){
                cout << "Do you want to equip/use an item? (y/n): ";
                char choice;
                cin >> choice;

                switch(toupper(choice)){
                    case 'Y':
                        cout << "Enter the number of the item to use/equip: ";
                        int itemNumber;
                        cin >> itemNumber;

                        if(itemNumber > 0 && itemNumber <= getPlayer()->inventory->itemsInInventory.size()) {
                            Item* selectedItem = getPlayer()->inventory->itemsInInventory[itemNumber - 1];
                            if (Weapon* weaponItem = dynamic_cast<Weapon*>(selectedItem)) {
                                if (weaponItem != getPlayer()->inventory->getEquippedWeapon())
                                    getPlayer()->inventory->equipWeapon(weaponItem);
                            } else if (Shield* shieldItem = dynamic_cast<Shield*>(selectedItem)) {
                                if (shieldItem != getPlayer()->inventory->getEquippedShield())
                                    getPlayer()->inventory->equipShield(shieldItem);
                            } else if (Potion* potionItem = dynamic_cast<Potion*>(selectedItem)) {
                                getPlayer()->inventory->usePotion(potionItem, getPlayer());
                            }
                        } else {
                            cout << "Invalid item number." << endl;
                        }
                        break;
                    case 'N':
                        cout << "You chose not to equip or use any item." << endl;
                        break;
                    default:
                        cout << "Wrong choice." << endl;
                }
            }
            else{
                cout << "Press ENTER to continue." << endl;
                cin.ignore();
                cin.get();
            }
            break;
        case 'H':
            this->displayHelp();
            cout << "Press ENTER to continue." << endl;
            cin.ignore();
            cin.get();
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

void Map::displayHelp(){
    system("CLS");
    cout << "----------------------" << endl;
    cout << "OBJECTS ON MAP" << endl;
    cout << "----------------------" << endl;
    cout << "| - Obstacle" << endl;
    cout << "P - Player" << endl;
    cout << "E - Enemy" << endl;
    cout << "M - Merchant (Shop)" << endl;
    cout << "Q - Quest" << endl;
    cout << "q - Quest in Progress (Accepted but not Completed)" << endl;
    cout << "I - Item on Map (Displays after accepting Quest)" << endl;
    cout << "L - Next Level (After all Quests are completed and all enemies are dead)" << endl;
    cout << "----------------------" << endl;
    cout << "INPUT" << endl;
    cout << "----------------------" << endl;
    cout << "W/A/S/D - Move player on map" << endl;
    cout << "i/I - Open inventory" << endl;
    cout << "l/L - Open quest list" << endl;
    cout << "h/H - Display Help" << endl;
    cout << "p/P - Pause the game and save" << endl;
    cout << "----------------------" << endl;
}

Player* Map::getPlayer() {
    return m_player;
}

void Map::setPlayer(Player* player) {
    this->m_player = player;
}

int Map::getCurrentLevel() {
    return currentLevel;
}
int Map::getTotalLevels() {
    return totalLevels;
}