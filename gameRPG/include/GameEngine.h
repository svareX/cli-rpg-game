//
// Created by stepa on 28.11.2023.
//

#ifndef GAMERPG_GAMEENGINE_H
#define GAMERPG_GAMEENGINE_H

#include "Player.h"
#include "Map.h"
#include "Enemy.h"

class GameEngine{
    Player* m_player;
    Map* m_map;
    int m_difficulty;
    int m_totalScore;

public:
    GameEngine();

    //loades after the game is started
    void startMenu();
    //selecting options from menu
    void menuSelection();
    //when you select play from menu
    void startGame();
    //combat
    void attackSequence(Enemy* enemy);
    //settings
    void startSettings();
    //selecting options from menu
    void settingsSelection();
    //when you die or something
    void stopGame();
    void setDifficulty(int newDifficulty);
    int getDifficulty();
    void addScore(Enemy* enemy);
    int getScore();
    ~GameEngine();
};

#endif //GAMERPG_GAMEENGINE_H
