#ifndef GAMERPG_MERCHANT_H
#define GAMERPG_MERCHANT_H

#include <vector>
#include "Item.h"
#include "Map.h"
using namespace std;

class Merchant{
    int m_merchantX;
    int m_merchantY;
    std::vector <Item*> m_items;
    Map* m_map; //merchant associated with map
public:
    Merchant(Map* gameMap);
    void displayShop();
    void buyItem(Item* product);
    void sellItem(Item* item);

    int getMerchantX();
    int getMerchantY();
};

#endif //GAMERPG_MERCHANT_H
