//
// Created by filip on 10.12.2023.
//
#include "../include/Score.h"

Score::Score() : m_totalScore(0) {}

void Score::updateScore(Enemy* enemy, GameEngine* gameEngine) {
    int enemyScore = (enemy->getHealth() + enemy->getDamage()) * gameEngine->getDifficulty();
    m_totalScore += enemyScore;
}

int Score::getScore() {
    return m_totalScore;
}
