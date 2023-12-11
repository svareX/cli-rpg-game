#include "../include/Merchant.h"
#include "../include/Map.h"
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;


//TODO: Add Quality to Weapons
Weapon* cSword = new Weapon("Common Sword", 10, 5, 100);
Weapon* rSword = new Weapon("Rare Sword", 20, 10, 100);
Weapon* eSword = new Weapon("Epic Sword", 30, 20, 100);

vector <Product> products = {
        {cSword, 50},
        {rSword, 100},
        {eSword, 150},
};

Merchant::Merchant(Map& map): map(map){
    int rndX = rand()% map.getSize();
    int rndY = rand()% map.getSize();
    map.gameMap[rndY][rndX] = 'M'; //temporary
    map.shop = this;
    items.insert(items.end(), products.begin(), products.end());
}
void Merchant::displayShop(){
    system("cls");
    vector <Item*> playerInventory = map.player->inventory->itemsInInventory;
    char choice;
    if (!items.empty() || !playerInventory.empty()){
        cout << "Hello, do you wanna buy some items? (B - Buy | S - Sell)" << endl;
        cin >> choice;
        switch (toupper(choice)){
            case 'B':
                char input;
                for (auto item : items){
                    cout << "Name: " << item.item->getName() << endl;
                    cout << "Price: " << item.goldAmount << endl;
                    cout << "-----------------------" << endl;
                }
                cin >> input;
                buyItem(items[(input - '0')-1]);
                break;
            case 'S':
                for (auto item: playerInventory){
                    cout << "Name: " << item->getName() << endl << "--------------------" << endl;
                }
                cin >> input;
                sellItem(playerInventory[(input - '0')-1]);
                break;
            default:
                return;
        }
    }
    else{
        cerr << "This shop has no items." << endl;
        cout << "Press ENTER to continue..." << endl;
        cin.ignore();
        cin.get();
    }
}

void Merchant::buyItem(Product product){
    if (map.player->getGoldAmount() >= product.goldAmount){
        map.player->inventory->addItem(product.item);
        auto boughtItem = [product](const Product& otherProduct) {
            return otherProduct.item == product.item;
        };
        auto x = find_if(items.begin(), items.end(), boughtItem);
        items.erase(x);
        map.player->setGoldAmount(map.player->getGoldAmount() - product.goldAmount);
        cout << "Successfully purchased item: " << product.item->getName() << endl;
    }
    else{
        cout << "You don't have enough gold to purchase this item." << endl;
    }
}

void Merchant::sellItem(Item* item){
    //TODO: Add "equation" for selling stuff (total_price = item.quality*10+item.stats+50) once quality for weapons is done
    system("CLS");
    map.player->setGoldAmount(map.player->getGoldAmount() + 50);
    auto x = find(map.player->inventory->itemsInInventory.begin(), map.player->inventory->itemsInInventory.end(), item);
    map.player->inventory->itemsInInventory.erase(x);
    cout << "Item has been successfully sold." << endl;
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