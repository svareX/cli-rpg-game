//
// Created by temel on 23.11.2023.
//
#include "../include/Player.h"
#include "../include/Quest.h"

#include <iostream>
#include <vector>

class Quest;

Player::Player(Map& gameMap): map(gameMap) {
    health = 100;
    strength = 2;
    playerX = 0;
    playerY = 0;
}

void Player::movePlayer(char move) {
    switch (toupper(move)) {
        case 'W':
            if (playerY > 0) {
                playerY--;
            } else {
                cerr << "You have reached the border!" << endl;
            }
            break;
        case 'A':
            if (playerX > 0) {
                playerX--;
            } else {
                cerr << "You have reached the border!" << endl;
            }
            break;
        case 'S':
            if (playerY < map_size - 1) {
                playerY++;
            } else {
                cerr << "You have reached the border!" << endl;
            }
            break;
        case 'D':
            if (playerX < map_size - 1) {
                playerX++;
            } else {
                cerr << "You have reached the border!" << endl;
            }
            break;
        case 'L':
            printQuestList();
            break;
    }
    if (playerX == 4 && playerY == 0) {
        attackSequence();
    }
    if (map.gameMap[playerY][playerX] == 'Q'){
        for(auto x : map.quests){
            if (x->getQuestGiverX() == playerX && x->getQuestGiverY() == playerY){
                x->display(this);
            }
        }
    }
    system("CLS");
}

void Player::attackSequence() {
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
                    eHealth = attack(eHealth, hStrength);
                    break;
            }
        }
        cout << "Enemy has been slained." << endl;
        map.gameMap[0][4] = '.';
        cin.ignore();
    }
}

int Player::attack(int eHealth, int hStrength) {
    eHealth -= hStrength;
    return eHealth;
}

void Player::acceptQuest(Quest *quest){
    QuestList.push_back(quest);
    quest->setQuestStatus(Pending);
    map.gameMap[quest->getQuestGiverY()][quest->getQuestGiverX()] = '.';
}

void Player::printQuestList(){
    system("CLS");
    int i = 1;
    if (!QuestList.empty()){
        for (auto quest : QuestList)
        {
            QuestGiven info = quest->getQuestInfo();
            cout << i << ". " << "Quest:" << endl;
            cout << info.task << endl;
            cout << "Status: " << quest->getQuestStatus() << endl;
            cout << "Gold amount: " << info.goldAmount << endl;
            cout << "---------------------------" << endl;
            i++;
        }
    }
    else{
        cout << "You currently have no quest." << endl;
    }
    cout << "Press Enter to Continue";
    cin.ignore();
    cin.get();
}

void Player::setPlayerX(int x) { playerX = x; }
void Player::setPlayerY(int y) { playerY = y; }
void Player::setHealth(int h) { health = h; }

int Player::getPlayerX() { return playerX; }
int Player::getPlayerY() { return playerY; }
int Player::getHealth() { return health; }
int Player::getStrength() { return strength; }