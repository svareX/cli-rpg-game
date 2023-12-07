//
// Created by temel on 23.11.2023.
//
#include "../include/Player.h"
#include "../include/Quest.h"

#include <iostream>
#include <vector>

class Quest;

Player::Player() {
    Inventory* inv = new Inventory();
    this->inventory = inv;
    health = 100;
    strength = 2;
}
Player::Player(Map* gameMap): map(gameMap) {
    Inventory *inv = new Inventory();
    this->inventory = inv;
    health = 100;
    strength = 2;
}

int Player::attack(int eHealth, int hStrength) {
    eHealth -= hStrength;
    return eHealth;
}
void Player::acceptQuest(Quest *quest){
    if (questList.size() < 3){
        questList.push_back(quest);
        quest->setQuestStatus(Pending);
        map->gameMap[quest->getQuestGiverY()][quest->getQuestGiverX()] = 'q';
    }
    else{
        system("cls");
        cerr << "You cannot accept more quest (Max amount: 3)" << endl;
    }
}

void Player::printQuestList(){
    system("CLS");
    int i = 1;
    if (!questList.empty()){
        for (auto quest : questList)
        {
            QuestGiven info = quest->getQuestInfo();
            cout << i << ". " << "Quest:" << endl;
            cout << info.task << endl;
            cout << "Status: " << quest->getQuestStatus() << endl;
            cout << "Gold amount: " << info.goldAmount << endl;
            cout << "Quest Item can be found on " << info.itemY << " | " << info.itemX << endl;
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
void Player::setHealth(int h) { health = h; }
int Player::getHealth() { return health; }
int Player::getStrength() { return strength; }
float Player::getGoldAmount() { return goldAmount;}
void Player::setGoldAmount(float gold) { goldAmount = gold;}