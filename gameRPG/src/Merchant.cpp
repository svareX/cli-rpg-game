#include "../include/Merchant.h"
#include "../include/Map.h"
#include "../include/Weapon.h"
#include "../include/Potion.h"
#include "../include/Item.h"
#include "../include/Logger.h"
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;

Weapon* cSword = new Weapon("Common Sword", 10, 5, 100, 0);
Weapon* rSword = new Weapon("Rare Sword", 20, 10, 100, 1);
Weapon* eSword = new Weapon("Epic Sword", 30, 20, 100, 2);

vector <Item*> items = {
        cSword, rSword, eSword
};

Potion* smallPotion = new Potion("Small HP Potion", 20);
Potion* mediumPotion = new Potion("Medium HP Potion", 40);
Potion* bigPotion = new Potion("Big HP Potion", 20);

vector <Item*> potions = {
        smallPotion, mediumPotion, bigPotion
};

Merchant::Merchant(Map* map): m_map(map){
    int rndX = rand()% map->getSize();
    int rndY = rand()% map->getSize();
    map->m_gameMap[rndY][rndX] = 'M';
    map->m_shop = this;
    m_items.insert(m_items.end(), items.begin(), items.end());
}
void Merchant::displayShop(){
    system("cls");
    vector <Item*> playerInventory = m_map->getPlayer()->inventory->itemsInInventory;
    char choice;
    Item* temp;
    bool isValidInput = false;
    int index = 1;
    if (!m_items.empty()){
        cout << "Hello, do you wanna buy some items? (B - Buy | S - Sell)" << endl;
        cin >> choice;
        switch (toupper(choice)){
            case 'B':
                char input;
                for (auto item : m_items){
                    float m_price = item->getQuality()*10+50;
                    cout << index << ". Item: " << endl;
                    cout << "Name: " << item->getName() << endl;
                    cout << "Price: " << m_price << endl;
                    cout << "Quality: " << item->getQualityName() << endl;
                    cout << "-----------------------" << endl;
                    index++;
                }
                cout << "Balance: " << m_map->getPlayer()->getGoldAmount() << endl;
                cout << "What item do you want to buy? (Input number): " << endl;
                cin >> input;
                while (!isValidInput) {
                    if (isdigit(input) && (input - '0') <= m_items.size() && input != '0') {
                        isValidInput = true;
                    } else {
                        cout << "Invalid input. Please enter a valid number from the list." << endl;
                        cout << "What item do you want to buy? (Input number): " << endl;
                        cin >> input;
                    }
                }
                temp = m_items[(input - '0')-1];
                buyItem(m_items[(input - '0')-1]);
                Logger::getInstance().log("[MERCHANT] You bought an item: " + temp->getName() + " for " + to_string((temp->getQuality()*10+50)) + " gold.  NEW BALLANCE: " + to_string(m_map->getPlayer()->getGoldAmount()));
                break;
            case 'S':
                if (empty(playerInventory)){
                    cout << "Your inventory is empty. You can't sell anything.";
                    cout << "Press ENTER to continue..." << endl;
                    cin.ignore();
                    cin.get();
                }
                else{
                    for (auto item: playerInventory){
                        cout << index << ". Item name: " << item->getName() << endl << "--------------------" << endl;
                    }
                    cin >> input;
                    while (!isValidInput) {
                        if (isdigit(input) && (input - '0') <= m_items.size() && input != '0') {
                            isValidInput = true;
                        } else {
                            cout << "Invalid input. Please enter a valid number from the list." << endl;
                            cout << "What item do you want to sell? (Input number): " << endl;
                            cin >> input;
                        }
                    }
                    temp = playerInventory[(input - '0')-1];
                    sellItem(playerInventory[(input - '0')-1]);
                    Logger::getInstance().log("[MERCHANT] You sold an item: " + temp->getName() + " for " + to_string((temp->getQuality()*10+50)/2) + " gold. NEW BALLANCE: " + to_string(m_map->getPlayer()->getGoldAmount()));
                }
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
    m_map->m_shop->m_items.push_back(item);
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