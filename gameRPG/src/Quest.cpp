#include "../include/Quest.h"
#include "../include/Map.h"
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

Item* amulet = new Item("Amulet", 50);
Item* axe = new Item("Axe", 100);
Item* rarePotion = new Item("Rare Potion", 75);
Item* treasureChest = new Item("Treasure Chest", 120);
Item* beastSkin = new Item("Beast Skin", 90);

vector <QuestGiven> quests = {
        {"Hello, can you please bring me my amulet? I lost it somewhere in the forest.", amulet, 50},
        {"Good evening to you traveller, can you please help me find my sacred axe? I will pay you accordingly.", axe, 100},
        {"Greetings, brave adventurer! I seek a rare potion. It is said to be hidden in a cave nearby.", rarePotion, 75},
        {"Ahoy there! My ship was wrecked, and I need help recovering the treasure chest. Care to lend a hand?", treasureChest, 120},
        {"Mysterious stranger, a dangerous beast roams the mountains. Defeat it, and I will reward you generously.", beastSkin, 90}
};


using namespace std;
Quest::Quest(Map* gameMap): m_map(gameMap){
    int rndX = rand()% m_map->getSize();
    int rndY = rand()% m_map->getSize();
    int random = rand()%quests.size();
    m_questGiverX = rndX;
    m_questGiverY = rndY;
    m_questInfo = quests[random];
    quests.erase(quests.begin() + random);
    m_questInfo.status = NotAccepted;
    m_map->addQuestToMap(this);
}

void Quest::display(Player* player){
    system("cls");
    char input;
    if (this->getQuestStatus() == "Not Accepted"){
        cout << m_questInfo.task << endl << "Reward: " << m_questInfo.goldAmount << " gold" << endl;
        cout << "Do you wanna add this quest to quest list? " << endl;
        cin >> input;
        switch(toupper(input)){
            case 'A':
                cout << "Added." << endl;
                player->acceptQuest(this);
                spawnQuestItem();
                break;
            case 'N':
                cout << "Ignored." << endl;
                break;
        }
    }
    else{
        if (player->inventory->containsItem(m_questInfo.itemRequired)){
            completeQuest();
        }
    }
    cout << "Press ENTER to continue..." << endl;
    cin.ignore();
    cin.get();
}
int Quest::getQuestGiverX(){
    return m_questGiverX;
}
int Quest::getQuestGiverY(){
    return m_questGiverY;
}

QuestGiven Quest::getQuestInfo() {
    return m_questInfo;
}

void Quest::setQuestStatus(enum Status Stat) {
    m_questInfo.status = Stat;
}

string Quest::getQuestStatus() {
    switch(m_questInfo.status){
        case 0:
            return "Not Accepted";
        case 1:
            return "Pending";
        default:
            return "Completed";
    }
}
void Quest::spawnQuestItem() {
    int rndX = rand()% m_map->getSize();
    int rndY = rand()% m_map->getSize();
    this->m_questInfo.itemX = rndX;
    this->m_questInfo.itemY = rndY;
    m_map->m_questItems.push_back({this->m_questInfo.itemRequired, rndX, rndY});
    m_map->gameMap[rndY][rndX] = 'I';
}
void Quest::completeQuest(){
    system("CLS");
    auto x = find(m_map->quests.begin(), m_map->quests.end(), this);
    m_map->quests.erase(x);
    x = find(m_map->getPlayer()->questList.begin(), m_map->getPlayer()->questList.end(), this);
    m_map->getPlayer()->questList.erase(x);
    m_map->gameMap[this->getQuestGiverY()][this->getQuestGiverX()] = '.';
    cout << "You handed over: " << this->m_questInfo.itemRequired->getName() << endl;
    cout << "Thank you for your help." << endl;
    // TODO: Add gold to totalGold of Player/Increase total score
}

