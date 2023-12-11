#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

#include "../include/Map.h"
#include "../include/Player.h"
#include "../include/Quest.h"
#include "../include/Weapon.h"
#include "../include/GameEngine.h"
using namespace std;

int main() {
    /*
    srand(time(0));
    Map* gameMap = new Map();
    Player* player = new Player(gameMap);
    player->setGoldAmount(500);
    gameMap->setPlayer(player);
    Quest* quest1 = new Quest(*gameMap);
    Quest* quest2 = new Quest(*gameMap);
    Merchant* shop = new Merchant(*gameMap);


    Map* gameMap = new Map();

    /*
    Player player(*gameMap);
    Weapon* zbran = new Weapon("Sword", 10, 10, 500);
    zbran->printInfo();
    char input;
    do{
        gameMap->displayMap();
        cout << "Where do you wanna move?" << endl;
        cin >> input;
        gameMap->movePlayer(input);
    } while (input != 'q');
    */
   srand(time(0));
   GameEngine* game = new GameEngine();
   game->startMenu();


    /*
    gameMap->changeMap(3,2,'Z');
    gameMap->changeMap(1,1,'X');
    gameMap->displayMap();
    gameMap->findEnemy(0,4);
     */
    gameMap->spawnRandomObjects(5);
    gameMap->spawnEnemies(3);
    gameMap->displayMap();
    return 0;
}
