#include "../include/Merchant.h"
#include "../include/Map.h"
#include <vector>
#include <cstdlib>
using namespace std;

Merchant::Merchant(Map& map): map(map){
    int rndX = rand()%map_size;
    int rndY = rand()%map_size;
    map.gameMap[rndY][rndX] = 'M'; //temporary
}
void Merchant::displayShop(){
    system("cls");
    cout << "Hello, do you wanna buy some items?";
    for (auto item : items){
        cout << "Item name: " << item.item << endl;
        cout << "Item price: " << item.goldAmount << endl;
        cout << "-----------------------" << endl;
    }
}