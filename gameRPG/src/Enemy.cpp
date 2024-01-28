//
// Created by stepa on 02.12.2023.
//
#include "../include/Enemy.h"
#include "../include/exceptions/DeadEnemyException.h"

using namespace std;

Enemy::Enemy(int health, int damage, int x, int y) {
    m_health = health;
    m_damage = damage;
    m_enemyX = x;
    m_enemyY = y;
}

void Enemy::setHealth(int health) {
    this->m_health = health;
}
void Enemy::removeHealth(int health) {
    this->m_health -= health;
}

int Enemy::getHealth() {
    return m_health;
};
int Enemy::getDamage() {
    return m_damage;
};
int Enemy::getEnemyX() {
    return m_enemyX;
};
int Enemy::getEnemyY() {
    return m_enemyY;
};

void Enemy::attack(Player* player, int difficulty) {
    player->removeHealth(this->getDamage()*difficulty);
}
