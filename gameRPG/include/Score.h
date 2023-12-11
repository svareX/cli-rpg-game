//
// Created by filip on 10.12.2023.
//

#ifndef GAMERPG_SCORE_H
#define GAMERPG_SCORE_H

#include "GameEngine.h"

class Score {
private:
    int m_totalScore;

public:
    Score();

    void addScore(Enemy* enemy, GameEngine* gameEngine);
    void addScore(Quest* quest, GameEngine* gameEngine);

    int getScore();

};

#endif //GAMERPG_SCORE_H

