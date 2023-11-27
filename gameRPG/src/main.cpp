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
    Weapon* zbran = new Weapon("Sword", 10, 10, 500);
    zbran->printInfo();
    Item* i = new Item();
    Item* ii = new Item("Test");
    Item* iii = new Item("Test", Item::Quality(2));
    cout << endl << i->getQuality();
    cout << endl << i->getIsEquipped();
    cout << endl << i->getName();
    cout << "********";
    cout << endl << ii->getQuality();
    cout << endl << ii->getIsEquipped();
    cout << endl << ii->getName();
    cout << "********";
    cout << endl << iii->getQuality();
    cout << endl << iii->getIsEquipped();
    cout << endl << iii->getName();
    cout << "********";
    iii->setIsEquipped();
    cout << endl << iii->getQuality();
    cout << endl << iii->getIsEquipped();
    cout << endl << iii->getName();
    cout << "********";


    /*
    char input;
    do{
        gameMap->displayMap(&player);
        cout << "Where do you wanna move?" << endl;
        cin >> input;
        player.movePlayer(input);
    } while (input != 'q');
     */

    return 0;
}
