#include <iostream>
#include <vector>
#include <windows.h>
#include <iomanip>

#include "../include/Map.h"
#include "../include/Player.h"

using namespace std;

int main() {
    Map* gameMap = new Map();
    Player player(*gameMap);

    char input;
    do{
        gameMap->displayMap(&player);
        cout << "Where do you wanna move?" << endl;
        cin >> input;
        player.movePlayer(input);
    } while (input != 'q');

    return 0;
}
