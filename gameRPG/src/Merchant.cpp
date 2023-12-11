#include "../include/Merchant.h"
#include "../include/Map.h"
#include "../include/Weapon.h"
#include "../include/Item.h"
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;


//TODO: Add Quality to Weapons
Weapon* cSword = new Weapon("Common Sword", 10, 5, 100, 0);
Weapon* rSword = new Weapon("Rare Sword", 20, 10, 100, 1);
Weapon* eSword = new Weapon("Epic Sword", 30, 20, 100, 2);

vector <Item*> items = {
        cSword, rSword, eSword
};

Merchant::Merchant(Map* map): m_map(map){
    int rndX = rand()% map->getSize();
    int rndY = rand()% map->getSize();
    map->gameMap[rndY][rndX] = 'M'; //temporary
    map->shop = this;
    m_items.insert(m_items.end(), items.begin(), items.end());
}
void Merchant::displayShop(){
    system("cls");
    vector <Item*> playerInventory = m_map->getPlayer()->inventory->itemsInInventory;
    char choice;
    if (!m_items.empty() || !playerInventory.empty()){
        cout << "Hello, do you wanna buy some items? (B - Buy | S - Sell)" << endl;
        cin >> choice;
        switch (toupper(choice)){
            case 'B':
                char input;
                for (auto item : m_items){
                    float m_price = item->getQuality()*10+50;
                    cout << "Name: " << item->getName() << endl;
                    cout << "Price: " << m_price << endl;
                    cout << "Quality: " << item->getQualityName() << endl;
                    cout << "-----------------------" << endl;
                }
                cout << "Balance: " << m_map->getPlayer()->getGoldAmount() << endl;
                cin >> input;
                buyItem(m_items[(input - '0')-1]);
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

void Merchant::buyItem(Item* product){
    if (m_map->getPlayer()->getGoldAmount() >= product->getQuality()*10+50){
        m_map->getPlayer()->inventory->addItem(product);
        auto x = find(m_items.begin(), m_items.end(), product);
        m_items.erase(x);
        float m_price = product->getQuality()*10+50;
        m_map->getPlayer()->setGoldAmount(m_map->getPlayer()->getGoldAmount() - m_price);
        cout << "Successfully purchased item: " << product->getName() << endl << "New Balance: " << m_map->getPlayer()->getGoldAmount();
    }
    else{
        cout << "You don't have enough gold to purchase this item." << endl;
    }
}

void Merchant::sellItem(Item* item){
    float m_totalPrice = (item->getQuality()*10+50)/2;
    system("CLS");
    m_map->getPlayer()->setGoldAmount(m_map->getPlayer()->getGoldAmount() + m_totalPrice);
    auto x = find(m_map->getPlayer()->inventory->itemsInInventory.begin(), m_map->getPlayer()->inventory->itemsInInventory.end(), item);
    m_map->shop->m_items.push_back(item);
    m_map->getPlayer()->inventory->itemsInInventory.erase(x);
    cout << "Item has been successfully sold." << endl;
    cout << "Press ENTER to continue..." << endl;
    cin.ignore();
    cin.get();
}

int Merchant::getMerchantX(){
    return m_merchantX;
}

int Merchant::getMerchantY(){
    return m_merchantY;
}