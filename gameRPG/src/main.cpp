#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include <iomanip>

#include "../include/Map.h"
#include "../include/Player.h"
#include "../include/Weapon.h"

using namespace std;

int main() {

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
        gameMap.movePlayer(input);
    } while (input != 'q');
    */

    /*
    gameMap->changeMap(3,2,'Z');
    gameMap->changeMap(1,1,'X');
    gameMap->displayMap();
    gameMap->findEnemy(0,4);
     */
    gameMap->spawnRandomObjects(5);
    gameMap->displayMap();
    return 0;
}
