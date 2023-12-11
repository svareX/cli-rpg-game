//
// Created by filip on 10.12.2023.
//

#ifndef GAMERPG_SCORE_H
#define GAMERPG_SCORE_H

#include "GameEngine.h"

class Score {
private:
    int totalScore;

public:
    Score();

    void updateScore(Enemy* enemy, GameEngine* gameEngine);

    int getScore();

};

#endif //GAMERPG_SCORE_H
