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
    Player player(*gameMap);
    Weapon* zbran = new Weapon("Mec", 10, 10, 500);
    zbran->printInfo();

    char input;
    do{
        gameMap->displayMap(&player);
        cout << "Where do you wanna move?" << endl;
        cin >> input;
        player.movePlayer(input);
    } while (input != 'q');

    return 0;
}
