//
// Created by stepa on 28.11.2023.
//
#include <iostream>
#include "../include/GameEngine.h"
#include "../include/exceptions/BorderException.h"
#include "../include/exceptions/EnemyException.h"
#include "../include/exceptions/GameOverException.h"

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
    //TODO: Change the starting gold amount according to difficulty
    this->m_player->setGoldAmount(500);
    this->m_map = new Map();
    this->m_map->setPlayer(this->m_player);

    //generate quests
    Quest* quest1 = new Quest(this->m_map);
    Quest* quest2 = new Quest(this->m_map);
    Merchant* shop = new Merchant(this->m_map);

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
            try {
                this->attackSequence(this->m_map->findEnemy(
                        this->m_map->getPlayerX(), this->m_map->getPlayerY()
                        ));
            } catch (GameOverException gameOverException) {
                //TODO: COUT SCORE OR SOMETHING
            }
        }
    } while (input != 'q');
}

void GameEngine::startSettings() {

}

void GameEngine::stopGame() {

}

void GameEngine::attackSequence(Enemy* enemy) {
    system("cls");
    char choice;
    cout << "You have encountered an enemy. Do you wanna fight? ";
    cin >> choice;
    if (toupper(choice) == 'N') {
        //TODO:
        /*
         * chance to avoid the fight:
         * easy - 75%
         * medium - 50%
         * hard - 25%
         */
        if(rand()%3 == 1) return;
    } else {
        int playerLast = 0;
        int enemyLast = 0;
        while (this->m_player->getHealth() != 0 && enemy->getHealth() != 0) {
            system("cls");
            cout << "Your Health: " << this->m_player->getHealth() << " | Enemy Health: " << enemy->getHealth() << endl;
            cout << "What do you wanna do? (1 - Attack): " << endl;
            cout << "What do you wanna do? (2 - Defend): " << endl;
            cout << "What do you wanna do? (3 - Dodge): " << endl;
            cout << "What do you wanna do? (4 - Inventory): " << endl;
            cout << "What do you wanna do? (5 - Run): ";
            cin >> choice;
            int enemyMove = rand()%3;
            while (enemyMove != enemyLast) {
                enemyMove = rand()%3;
            }
            //TODO: ADD DIFICULTY DAMAGE MULTIPLIERS
            //TODO: ADD EQUIPPED ITEM (WEAPON, SHIELD) DAMAGE MULTIPLIERS
            if (playerLast != int(choice)) {
                switch (choice) {
                    case '1':
                        if (enemyMove == 1) {
                            //oba seknou => oba dostanou dmg
                            this->m_player->removeHealth(enemy->getDamage());
                            enemy->removeHealth(this->m_player->getDamage());
                        } else if (enemyMove == 2) {
                            //hrac sekne & enemy se brani => hrac dostane dmg
                            this->m_player->removeHealth(this->m_player->getDamage());
                        } else {
                            //hrac seka a enemy dodguje => nic
                        }
                        break;
                    case '2':
                        if (enemyMove == 2) {
                            //oba se brani => nestane se nic
                        } else if (enemyMove == 1) {
                            //ty se branis & enemy sekne => enemy dostane dmg
                            enemy->removeHealth(enemy->getDamage());
                        } else {
                            //hrac se brani a enemy doguje => nic
                        }
                        break;
                    case '3':
                        //vzdycky nic (akorat nacist previous move)
                        break;
                    case '4':
                        //TODO: OPEN INVENTORY
                        //POTREBUJU ABY FILIP UZ NECO KONECNO UDELAL
                        break;
                    case '5':
                        //TODO: přidat zase šanci na útěk jako nahoře akorát
                        // že ta šance bude ještě * 1/2 (poloviční), protože už jsi v boji
                        break;
                }
            } else {
                cout << endl << "You cannot choose the same thing twice in a row!";
            }
            playerLast = int(choice);
            enemyLast = enemyMove;
        }
        cout << "Enemy has been slain." << endl;
        this->m_map->changeMap(enemy->getEnemyX(), enemy->getEnemyY(), '.');
        cin.ignore();
    }
}

GameEngine::~GameEngine() {
    delete(this->m_map);
    this->m_map = nullptr;
    delete(this->m_player);
    this->m_player = nullptr;
}