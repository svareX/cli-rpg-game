#include "../include/Merchant.h"
#include "../include/Map.h"
#include <vector>
#include <cstdlib>
using namespace std;

Merchant::Merchant(Map& map): map(map){
    int rndX = rand()%map_size;
    int rndY = rand()%map_size;
    map.gameMap[rndY][rndX] = 'M'; //temporary
    map.shop = this;
}
void Merchant::displayShop(){
    system("cls");
    if (!items.empty()){
        cout << "Hello, do you wanna buy some items?" << endl;
        for (auto item : items){
            cout << "Item name: " << item.item << endl;
            cout << "Item price: " << item.goldAmount << endl;
            cout << "-----------------------" << endl;
        }
    }
    else{
        cerr << "This shop has no items." << endl;
    }
    cout << "Press ENTER to continue..." << endl;
    cin.ignore();
    cin.get();
}

int Merchant::getMerchantX(){
    return merchantX;
}

int Merchant::getMerchantY(){
    return merchantY;
}