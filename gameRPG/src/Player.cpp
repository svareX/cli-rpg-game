//
// Created by temel on 23.11.2023.
//
#include "../include/Player.h"
#include "../include/Map.h"
#include <iostream>
#include <vector>

using namespace std;

Player::Player(Map& gameMap): map(gameMap) {
    health = 100;
    strength = 2;
    playerX = 0;
    playerY = 0;
}


int Player::attack(int eHealth, int hStrength) {
    eHealth -= hStrength;
    return eHealth;
}

void Player::setPlayerX(int x) { playerX = x; }
void Player::setPlayerY(int y) { playerY = y; }
void Player::setHealth(int h) { health = h; }

int Player::getPlayerX() { return playerX; }
int Player::getPlayerY() { return playerY; }
int Player::getHealth() { return health; }
int Player::getStrength() { return strength; }