//
// Created by filip on 10.12.2023.
//

#ifndef GAMERPG_SCORE_H
#define GAMERPG_SCORE_H


#include "Enemy.h"
#include "Quest.h"

class Score {
private:
    int m_totalScore;

public:
    Score();

    void addScore(Enemy* enemy, int multiplier);
    void addScore(Quest* quest, int multiplier);

    int getScore();

};

#endif //GAMERPG_SCORE_H

