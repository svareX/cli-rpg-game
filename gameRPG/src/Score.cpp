//
// Created by filip on 10.12.2023.
//
#include "../include/Score.h"

Score::Score() {
    this->m_totalScore = 0;
}

void Score::addScore(Enemy* enemy, int multiplier) {
    int enemyScore = (enemy->getHealth() + enemy->getDamage()) * multiplier;
    m_totalScore += enemyScore;
}
void Score::addScore(Quest* quest, int multiplier) {
    m_totalScore += 50 * multiplier;
}

int Score::getScore() {
    return m_totalScore;
}
