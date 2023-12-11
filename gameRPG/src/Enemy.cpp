//
// Created by stepa on 02.12.2023.
//
#include "../include/Enemy.h"
#include "../include/exceptions/DeadEnemyException.h"

using namespace std;

//TODO: ADD ENEMY INVENTORY => EQUIPPED ITEMS, QUEST ITEMS

/*
Enemy::Enemy() {
    //HEALTH <80, 120>
    //DAMAGE <5,15>
    m_health = 80 + (rand() % 40);
    m_damage = 5 + (rand() % 10);
    m_enemyX = rand() % map_size + 1;
    m_enemyY = rand() % map_size + 0;
};

Enemy::Enemy(int health, int damage) {
    m_health = health;
    m_damage = damage;
    m_enemyX = rand() % map_size + 1;
    m_enemyY = rand() % map_size + 0;
}
*/

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
