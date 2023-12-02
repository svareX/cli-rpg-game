//
// Created by temel on 23.11.2023.
//
#include "../include/Player.h"
#include "../include/Map.h"
#include <iostream>
#include <vector>

using namespace std;

Player::Player() {
    m_health = 100;
    m_strength = 2;
}
Player::Player(Map* gameMap): map(gameMap) {
    m_health = 100;
    m_strength = 2;
}


void Player::attack(Enemy* enemy) {
    int enemyDamage = 0;
    int playerDamage = 0;
    this->setHealth(enemyDamage);
    enemy->setHealth(playerDamage);
}

void Player::setHealth(int health) {
    m_health = health;
}
void Player::removeHealth(int health) {
    this->m_health -= health;
}

int Player::getHealth() { return m_health; }
int Player::getStrength() { return m_strength; }