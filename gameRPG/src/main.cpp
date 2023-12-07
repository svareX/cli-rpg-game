#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include <iomanip>

#include "../include/Map.h"
#include "../include/Player.h"
<<<<<<< HEAD
#include "../include/Quest.h"
=======
#include "../include/Weapon.h"
#include "../include/GameEngine.h"
>>>>>>> origin/inventory

using namespace std;

int main() {
<<<<<<< HEAD
    srand(time(0));
    Map* gameMap = new Map();
    Player player(*gameMap);
    Quest* quest1 = new Quest(*gameMap);
    Quest* quest2 = new Quest(*gameMap);

=======
   /*
    Map* gameMap = new Map();
    Player player(*gameMap);
    Weapon* zbran = new Weapon("Sword", 10, 10, 500);
    zbran->printInfo();
>>>>>>> origin/inventory
    char input;
    do{
        gameMap->displayMap();
        cout << "Where do you wanna move?" << endl;
        cin >> input;
        gameMap.movePlayer(input);
    } while (input != 'q');
    */
   GameEngine* game = new GameEngine();
   game->startMenu();

    return 0;
}
