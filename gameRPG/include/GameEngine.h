//
// Created by stepa on 28.11.2023.
//

#ifndef GAMERPG_GAMEENGINE_H
#define GAMERPG_GAMEENGINE_H

#include "Player.h"
#include "Map.h"

class GameEngine{
    Player* m_player;
    Map* m_map;
    //TODO: add setings + scores

public:
    GameEngine();

    //loades after the game is started
    void startMenu();
    //selecting options from menu
    void menuSelection();
    //when you select play from menu
    void startGame();
    //settings
    void startSettings();
    //when you die or something
    void stopGame();

    ~GameEngine();
};

#endif //GAMERPG_GAMEENGINE_H
