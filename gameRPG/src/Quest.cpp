//
// Created by temel on 24.11.2023.
//

#include "../include/Quest.h"

Quest::Quest(Map& gameMap): map(gameMap){
    questGiverX = 2;
    questGiverY = 2; //X & Y will be random generated in future
    map.gameMap[questGiverY][questGiverX] = 'Q';
}
