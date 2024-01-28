#include "../include/Quest.h"
#include "../include/Map.h"
#include "../include/Logger.h"
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <algorithm>
#include <sstream>

using namespace std;

QuestGiven getQuestFromFile(){
    QuestGiven qg;
    ifstream file("../quests.txt");

    string lines[25];
    int count = 0;
    while (getline(file, lines[count])) {
        count++;
    }
    int randomNum = rand() % count;
    string task; string itemName; int gold;
    file.close();
    stringstream lineStream(lines[randomNum]);
    getline(lineStream, task, ';');
    getline(lineStream, itemName, ';');
    lineStream >> gold;

    qg.task = task;
    Item* item = new Item(itemName);
    qg.itemRequired = item;
    qg.goldAmount = gold;
    return qg;
}
Quest::Quest(Map* gameMap): m_map(gameMap){
    int rndX = rand()% m_map->getSize();
    int rndY = rand()% m_map->getSize();
    do {
        rndX = std::rand() % m_map->getSize();
        rndY = std::rand() % m_map->getSize();
    } while (m_map->m_gameMap[rndX][rndY] != '.' || (rndX == m_map->getPlayerX() && rndY == m_map->getPlayerY()));
//    int random = rand()%quests.size();
    m_questGiverX = rndX;
    m_questGiverY = rndY;
    ifstream file("../quests.txt");
    m_questInfo = getQuestFromFile();
//    m_questInfo = quests[random];
//    quests.erase(quests.begin() + random);
    m_questInfo.status = NotAccepted;
    m_map->addQuestToMap(this);
}

void Quest::display(Player* player){
    system("cls");
    char input;
    if (this->getQuestStatus() == "Not Accepted"){
        cout << m_questInfo.task << endl << "Reward: " << m_questInfo.goldAmount << " gold" << endl;
        cout << "Do you wanna add this quest to quest list? (Y - Yes | N - No)" << endl;
        cin >> input;
        switch(toupper(input)){
            case 'Y':
                cout << "Quest was added to Quest List." << endl;
                player->acceptQuest(this);
                spawnQuestItem();
                break;
            case 'N':
                cout << "Quest was ignored." << endl;
                break;
            default:
                return;
        }
    }
    else{
        if (player->inventory->containsItem(m_questInfo.itemRequired)){
            completeQuest();
        }
        else{
            cout << "You still don't have the required item in your inventory." << endl;
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
    do {
        rndX = std::rand() % m_map->getSize();
        rndY = std::rand() % m_map->getSize();
    } while (m_map->m_gameMap[rndX][rndY] != '.' || (rndX == m_map->getPlayerX() && rndY == m_map->getPlayerY()));
    this->m_questInfo.itemX = rndX;
    this->m_questInfo.itemY = rndY;
    m_map->m_questItems.push_back({this->m_questInfo.itemRequired, rndX, rndY});
    m_map->m_gameMap[rndY][rndX] = 'I';
}
void Quest::completeQuest(){
    Player* player = m_map->getPlayer();
    system("CLS");
    auto x = find(m_map->m_quests.begin(), m_map->m_quests.end(), this);
    m_map->m_quests.erase(x);
    x = find(player->questList.begin(), m_map->getPlayer()->questList.end(), this);
    m_map->getPlayer()->questList.erase(x);
    m_map->m_gameMap[this->getQuestGiverY()][this->getQuestGiverX()] = '.';
    cout << "You handed over: " << this->m_questInfo.itemRequired->getName() << endl;
    auto questItem = find(m_map->getPlayer()->inventory->itemsInInventory.begin(), m_map->getPlayer()->inventory->itemsInInventory.end(), m_questInfo.itemRequired);
    player->inventory->itemsInInventory.erase(questItem);
    player->setGoldAmount(player->getGoldAmount()+this->m_questInfo.goldAmount);
    cout << "Thank you for your help." << endl;
    Logger::getInstance().log("[QUEST] You completed a quest!");
    player->setScore(5);
}