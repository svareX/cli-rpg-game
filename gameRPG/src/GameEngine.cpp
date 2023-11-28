//
// Created by stepa on 28.11.2023.
//
#include <iostream>
#include "../include/GameEngine.h"
#include "../include/exceptions/BorderException.h"
#include "../include/exceptions/EnemyException.h"

using namespace std;
GameEngine::GameEngine() {
    this->m_map = nullptr;
    this->m_player = nullptr;
}

void GameEngine::startMenu() {
    cout << endl << "*************************" << endl;
    cout << "Play (1)" << endl;
    cout << "Settings (2)" << endl;
    cout << "Quit (3)";
    cout << endl << "*************************" << endl;
    menuSelection();
}

void GameEngine::menuSelection() {
    char input;
    cin.get(input);
    if (input == '1') {
        startGame();
    } else if (input == '2') {
        startSettings();
    } else if (input == '3') {
        abort();
    } else {
        cout << endl << "Please choose one of the options above!" << endl;
        menuSelection();
    }
}

void GameEngine::startGame() {
    //create player according to settings
    this->m_player = new Player();
    this->m_map = new Map();
    char input;
    do{
        this->m_map->displayMap();
        cout << "Where do you wanna move?" << endl;
        cin >> input;
        try {
            this->m_map->movePlayer(input);
        } catch (BorderException borderException){
            cout << "Border hit";
        } catch (EnemyException enemyException) {
            this->m_map->attackSequence();
        }
    } while (input != 'q');
}

void GameEngine::startSettings() {

}

void GameEngine::stopGame() {

}

GameEngine::~GameEngine() {
    delete(this->m_map);
    this->m_map = nullptr;
    delete(this->m_player);
    this->m_player = nullptr;
}