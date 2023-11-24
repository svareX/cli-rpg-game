//
// Created by temel on 23.11.2023.
//
#include <iostream>
#include <vector>
#include <iomanip>
#include "../include/Map.h"
#include "../include/Player.h"
using namespace std;
Map::Map(){
    for(int i = 0; i < map_size; i++){
        vector<char> row(map_size, '.');
        gameMap.push_back(row);
    }
    gameMap[3][2] = 'G';
    gameMap[0][4] = 'X';
}

void Map::displayMap(Player* player){
    system("cls");
    for (int i = 0; i < map_size; i++){
        for (int j = 0; j < map_size; j++){
            if (i == player->getPlayerY() && j == player->getPlayerX()){
                cout << setw(2) << 'P';
            }
            else{
                cout << setw(2) << gameMap[i][j];
            }
        }
        cout << endl;
    }
}