//
// Created by temel on 23.11.2023.
//
#include "../include/Player.h"
#include "../include/Quest.h"
#include "../include/exceptions/GameOverException.h"

#include <iostream>
#include <vector>

class Quest;

Player::Player() {
    Inventory* inv = new Inventory();
    this->inventory = inv;
    m_health = 100;
    m_strength = 10;
}
Player::Player(Map* gameMap): m_map(gameMap) {
    Inventory *inv = new Inventory();
    this->inventory = inv;
    m_health = 100;
    m_strength = 2;
}

void Player::acceptQuest(Quest *quest){
    if (questList.size() < 3){
        questList.push_back(quest);
        quest->setQuestStatus(Pending);
        m_map->m_gameMap[quest->getQuestGiverY()][quest->getQuestGiverX()] = 'q';
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
void Player::setHealth(int h) { m_health = h; }
int Player::getHealth() { return m_health; }
int Player::getDamage() {
    if (this->inventory->getEquippedWeapon() != nullptr) {
        return m_strength + this->inventory->getEquippedWeapon()->getDamage();
    }
    return m_strength;
}
float Player::getGoldAmount() { return m_goldAmount;}
void Player::setGoldAmount(float gold) { m_goldAmount = gold;}

void Player::removeHealth(int health) {
    if (this->inventory->getEquippedShield() != nullptr) {
        health -= this->inventory->getEquippedShield()->getDamage();
    }
    this->m_health -= health;
}