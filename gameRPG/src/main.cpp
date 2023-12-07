#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include <iomanip>

#include "../include/Map.h"
#include "../include/Player.h"
#include "../include/Quest.h"
#include "../include/Weapon.h"
#include "../include/GameEngine.h"
using namespace std;

int main() {
    srand(time(0));
    Map* gameMap = new Map();
    Player* player = new Player(gameMap);
    gameMap->setPlayer(player);
    Quest* quest1 = new Quest(*gameMap);
    Quest* quest2 = new Quest(*gameMap);
    Weapon* zbran = new Weapon("Sword", 10, 10, 500);
    zbran->printInfo();
    Merchant* shop = new Merchant(*gameMap);
    char input;
    do{
        gameMap->displayMap();
        cout << "Where do you wanna move?" << endl;
        cin >> input;
        gameMap->movePlayer(input);
    } while (input != 'q');
   GameEngine* game = new GameEngine();
   game->startMenu();

    return 0;
}
