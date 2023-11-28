//
// Created by temel on 23.11.2023.
//
#include "../include/Player.h"
#include "../include/Map.h"
#include <iostream>
#include <vector>

using namespace std;

Player::Player() {
    health = 100;
    strength = 2;
}
Player::Player(Map* gameMap): map(gameMap) {
    health = 100;
    strength = 2;
}


int Player::attack(int eHealth, int hStrength) {
    eHealth -= hStrength;
    return eHealth;
}

void Player::setHealth(int h) { health = h; }

int Player::getHealth() { return health; }
int Player::getStrength() { return strength; }