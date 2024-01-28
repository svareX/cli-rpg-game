//
// Created by stepa on 28.11.2023.
//
#include <iostream>
#include "../include/GameEngine.h"
#include "../include/exceptions/BorderException.h"
#include "../include/exceptions/EnemyException.h"
#include "../include/exceptions/GameOverException.h"
#include "../include/exceptions/DeadEnemyException.h"
#include "../include/Logger.h"
#include <algorithm>

using namespace std;

GameEngine::GameEngine() {
    this->m_map = nullptr;
    this->m_player = nullptr;
    m_totalScore = 0;
    this->m_difficulty = 1;
}

void GameEngine::setDifficulty(int newDifficulty) {
    m_difficulty = newDifficulty;
}

int GameEngine::getDifficulty() {
    return m_difficulty;
}

void GameEngine::addScore(Enemy *enemy) {
    int enemyScore = (enemy->getHealth() + enemy->getDamage()) * this->getDifficulty();
    m_totalScore += enemyScore;
}

int GameEngine::getScore() {
    return m_totalScore;
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
    cin >> input;
    if (input == '1') {
        startGame();
    } else if (input == '2') {
        startSettings();
    } else if (input == '3') {
        return;
    } else {
        cout << endl << "Please choose one of the options above!" << endl;
        menuSelection();
    }
}

void GameEngine::startGame() {
    //create player according to settings
    this->m_player = new Player();
    //TODO: Change the starting gold amount according to m_difficulty
    this->m_player->setGoldAmount(500);
    this->m_map = new Map();
    this->m_map->setPlayer(this->m_player);
    this->m_totalScore = 0;
    this->m_player->setMap(m_map);

    //generate quests
    Quest *quest1 = new Quest(this->m_map);
    Quest *quest2 = new Quest(this->m_map);
    Merchant *shop = new Merchant(this->m_map);
    char input;
    do {
        this->m_map->displayMap();
        cout << "Where do you wanna move?" << endl;
        cin >> input;
        try {
            this->m_map->movePlayer(input);
            if (this->m_map->getCurrentLevel() == this->m_map->getTotalLevels() && this->m_map->m_quests.empty() && this->m_map->m_enemies.empty())
                this->stopGame();
        } catch (BorderException borderException) {
            cout << "Border hit";
            Logger::getInstance().log("[ERROR] You hit the map border.");
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
    cout << endl << "*************************" << endl;
    cout << "Difficulty: " << endl;
    cout << "Easy (1)";
    if (this->getDifficulty() == 1) {
        cout << " - selected" << endl;
    }
    if (this->getDifficulty() != 1) {
        cout << endl;
    }
    cout << "Medium (2)";
    if (this->getDifficulty() == 2) {
        cout << " - selected" << endl;
    }
    if (this->getDifficulty() != 2) {
        cout << endl;
    }
    cout << "Hard (3)";
    if (this->getDifficulty() == 3) {
        cout << " - selected" << endl;
    }
    cout << endl << "*************************" << endl;
    settingsSelection();
}

void GameEngine::settingsSelection() {
    char input;
    cin >> input;
    if (input == '1') {
        this->setDifficulty(1);
    } else if (input == '2') {
        this->setDifficulty(2);
    } else if (input == '3') {
        this->setDifficulty(3);
    }
    startMenu();
}
void GameEngine::stopGame() {
    system("CLS");
    if (m_player->getHealth() <= 0)
        cout << "You have died." << endl;
    else
        cout << "You have won, congratulations." << endl;
    cout << "Gold: " << m_player->getGoldAmount() << endl;
    cout << "Score: " << this->m_totalScore << endl;
    cout << "Press Enter to exit...";
    cin.ignore();
    cin.get();
    exit(EXIT_SUCCESS);
}

void GameEngine::attackSequence(Enemy *enemy) {
    Enemy* temp = enemy;
    vector<Potion*> potions;
    int inventoryCount = 0;
    srand(time(0));
    system("cls");
    char choice;
    cout << "You have encountered an enemy. Do you wanna fight? ";
    Logger::getInstance().log("[COMBAT START] You have encountered an enemy. PLAYER HEALTH: " + to_string(this->m_player->getHealth()) + " | ENEMY HEALTH: " + to_string(enemy->getHealth()));
    cin >> choice;
    if (toupper(choice) == 'N') {
        /*
         * chance to avoid the fight:
         * easy - 75%
         * medium - 50%
         * hard - 25%
         */
        if (this->getDifficulty() == 1) {
            if (rand() % 4 == 0 || rand() % 4 == 1 || rand() % 4 == 2) return;
        } else if (this->getDifficulty() == 2) {
            if (rand() % 4 == 0 || rand() % 4 == 1) return;
        } else {
            if (rand() % 4 == 0) return;
        }
    }

    int playerLast = 0;
    int enemyLast = 0;
    while (this->m_player->getHealth() > 0 && enemy->getHealth() > 0) {
        cout << "Your Health: " << this->m_player->getHealth() << " | Enemy Health: " << enemy->getHealth() << endl;
        cout << "What do you wanna do? (1 - Attack): " << endl;
        cout << "What do you wanna do? (2 - Defend): " << endl;
        cout << "What do you wanna do? (3 - Dodge): " << endl;
        cout << "What do you wanna do? (4 - Inventory): " << endl;
        cout << "What do you wanna do? (5 - Run): ";
        cin >> choice;
        int enemyMove = rand() % 3;
        while (enemyMove == enemyLast) {
            enemyMove = rand() % 3;
        }
        cout << endl << "Enemy:" << enemyMove << " | Player: " << choice << endl;
        if (playerLast != int(choice)) {
            switch (choice) {
                case '1':
                    if (enemyMove == 0) {
                        //oba seknou => oba dostanou dmg
                        enemy->attack(this->m_player, this->getDifficulty());
                        this->m_player->attack(enemy);
                        Logger::getInstance().log("[COMBAT] You and enemy attacked each other. PLAYER HEALTH: " + to_string(this->m_player->getHealth()) + " | ENEMY HEALTH: " + to_string(enemy->getHealth()));
                    } else if (enemyMove == 1) {
                        //hrac sekne & enemy se brani => hrac dostane dmg
                        enemy->attack(this->m_player, this->getDifficulty());
                        Logger::getInstance().log("[COMBAT] Enemy reflected your attack. PLAYER HEALTH: " + to_string(this->m_player->getHealth()));
                    } else {
                        //hrac seka a enemy dodguje => nic
                        Logger::getInstance().log("[COMBAT] Player attacked, enemy dodged, nothing happened.");
                    }
                    break;
                case '2':
                    if (enemyMove == 1) {
                        Logger::getInstance().log("[COMBAT] Player and enemy blocked, nothing happened.");
                        //oba se brani => nestane se nic
                    } else if (enemyMove == 0) {
                        //ty se branis & enemy sekne => enemy dostane dmg
                        this->m_player->attack(enemy);
                        Logger::getInstance().log("[COMBAT] Player reflected enemy's attack. ENEMY HEALTH: " + to_string(enemy->getHealth()));
                    } else {
                        //hrac se brani a enemy doguje => nic
                        Logger::getInstance().log("[COMBAT] Player blocked, enemy dodged, nothing happened.");
                    }
                    break;
                case '3':
                    //vzdycky nic (akorat nacist previous move)
                    break;
                case '4':
                    if(inventoryCount != 1){
                        int index;
                        index = 1;
                        for (const auto& item : m_player->inventory->itemsInInventory) {
                            Potion* potion = dynamic_cast<Potion*>(item);
                            if (potion != nullptr) {
                                std::cout << index << ". " << potion->getName() << std::endl;
                                potions.push_back(potion);
                                index++;
                            }
                        }
                        if (!m_player->inventory->itemsInInventory.empty()) {
                            std::cout << "Enter the number of the potion to use: ";
                            int potionNumber;
                            cin >> potionNumber;

                            if (potionNumber > 0 && potionNumber <= m_player->inventory->itemsInInventory.size()) {
                                auto it = find(m_player->inventory->itemsInInventory.begin(), m_player->inventory->itemsInInventory.end(), potions[potionNumber - 1]);
                                Potion* selectedPotion = dynamic_cast<Potion*>(*it);
                                if (selectedPotion != nullptr) {
                                    m_player->inventory->usePotion(selectedPotion, this->m_player);
                                } else {
                                    cout << "Invalid potion selection." << endl;
                                }
                            } else {
                                cout << "Invalid potion number." << endl;
                            }
                        } else {
                            cout << "Inventory is empty." << endl;
                        }
                        inventoryCount++;
                    }
                    else{
                        cout << "You can't use inventory in this fight anymore." << endl;
                        cin.ignore();
                        cin.get();
                    }
                    break;
                case '5':
                    /*
                     * chance to leave the fight:
                     * easy - 30%
                     * medium - 20%
                     * hard - 10%
                     */
                    if (this->getDifficulty() == 1) {
                        if (rand() % 10 == 0 || rand() % 10 == 1 || rand() % 10 == 2) Logger::getInstance().log("[COMBAT END] Player escaped the combat."); return;
                    } else if (this->getDifficulty() == 2) {
                        if (rand() % 10 == 0 || rand() % 10 == 1) Logger::getInstance().log("[COMBAT END] Player escaped the combat."); return;
                    } else {
                        if (rand() % 10 == 0) Logger::getInstance().log("[COMBAT END] Player escaped the combat."); return;
                    }
                    break;
                default:
                    cout << "Incorrect option chosen!";
                    break;
            }
        } else {
            cout << endl << "You cannot choose the same thing twice in a row!" << endl;
        }
        playerLast = int(choice);
        enemyLast = enemyMove;
    }
    if (m_player->getHealth() > 0) {
        cout << "Enemy has been slain." << endl;
        Logger::getInstance().log("[COMBAT END] Enemy has been slain.");
        this->m_map->changeMap(enemy->getEnemyX(), enemy->getEnemyY(), '.');
        this->addScore(temp);
    } else {
        cout << "You have died." << endl;
        Logger::getInstance().log("[COMBAT END] You have died.");
        Logger::getInstance().log("[GAME OVER] FINAL SCORE: " + to_string(m_player->getScore()));
        this->stopGame();
    }
}

GameEngine::~GameEngine() {
    delete (this->m_map);
    this->m_map = nullptr;
    delete (this->m_player);
    this->m_player = nullptr;
}