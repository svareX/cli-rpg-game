//
// Created by temel on 23.11.2023.
//
#include "../include/Player.h"
#include "../include/Map.h"
#include "../include/exceptions/GameOverException.h"
#include <iostream>
#include <vector>

using namespace std;

Player::Player() {
    m_health = 100;
    m_damage = 2;
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
    if (m_health - health > 0) {
        this->m_health -= health;
    } else {
        throw GameOverException();
    }
}

int Player::getHealth() { return m_health; }
int Player::getDamage() { return m_damage; }