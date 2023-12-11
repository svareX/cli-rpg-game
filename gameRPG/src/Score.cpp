//
// Created by filip on 10.12.2023.
//
#include "../include/Score.h"

Score::Score() : totalScore(0) {}

void Score::updateScore(Enemy* enemy, GameEngine* gameEngine) {
    int enemyScore = (enemy->getHealth() + enemy->getDamage()) * gameEngine->getDifficulty();
    totalScore += enemyScore;
}

int Score::getScore() {
    return totalScore;
}
