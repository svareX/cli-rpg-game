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
    srand(time(0));
    GameEngine* m_game = new GameEngine();
    m_game->startMenu();
    delete m_game;
    return 0;
}
