#ifndef GAMERPG_MERCHANT_H
#define GAMERPG_MERCHANT_H

#include <vector>
#include "Item.h"
#include "Map.h"
using namespace std;

struct Product{
    Item* item;
    float goldAmount;
};


class Merchant{
    int merchantX;
    int merchantY;
    std::vector <Product> items;
    Map& map; //merchant associated with map
public:
    Merchant(Map& gameMap);
    void displayShop();
    void buyItem(Product item);
    void sellItem(Item* item);

    int getMerchantX();
    int getMerchantY();
    // add global function addToMap to GameEngine, parameters: coordinates X&Y and an object
};

#endif //GAMERPG_MERCHANT_H
