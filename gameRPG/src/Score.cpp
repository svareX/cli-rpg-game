//
// Created by filip on 10.12.2023.
//
#include "../include/Score.h"

Score::Score() {
    this->m_totalScore = 0;
}

void Score::addScore(Enemy* enemy, GameEngine* gameEngine) {
    int enemyScore = (enemy->getHealth() + enemy->getDamage()) * gameEngine->getDifficulty();
    m_totalScore += enemyScore;
}
void Score::addScore(Quest* quest, GameEngine* gameEngine) {
    m_totalScore += 50 * gameEngine->getDifficulty();
}

int Score::getScore() {
    return m_totalScore;
}
