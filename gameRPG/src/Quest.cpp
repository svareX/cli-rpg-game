//
// Created by temel on 24.11.2023.
//

#include "../include/Quest.h"
#include "../include/Map.h"
#include <vector>
#include <cstdlib>
#include <ctime>

Item* amulet = new Item();
Item* axe = new Item();
Item* rarePotion = new Item();
Item* treasureChest = new Item();
Item* beastSkin = new Item();

vector <QuestGiven> quests = {
        {"Hello, can you please bring me my amulet? I lost it somewhere in the forest.", amulet, 50},
        {"Good evening to you traveller, can you please help me find my sacred axe? I will pay you accordingly.", axe, 100},
        {"Greetings, brave adventurer! I seek a rare potion. It is said to be hidden in a cave nearby.", rarePotion, 75},
        {"Ahoy there! My ship was wrecked, and I need help recovering the treasure chest. Care to lend a hand?", treasureChest, 120},
        {"Mysterious stranger, a dangerous beast roams the mountains. Defeat it, and I will reward you generously.", beastSkin, 90}
};


using namespace std;
Quest::Quest(Map& gameMap): map(gameMap){
    int rndX = rand()% map_size;
    int rndY = rand()% map_size;
    int random = rand()%quests.size();
    questGiverX = rndX;
    questGiverY = rndY;
    questInfo = quests[random];
    quests.erase(quests.begin() + random);
    questInfo.status = NotAccepted;
    map.addQuestToMap(this);
}

void Quest::display(Player* player){
    system("cls");
    char input;
    cout << questInfo.task << endl << "Reward: " << questInfo.goldAmount << " gold" << endl;
    cout << "Do you wanna add this quest to quest list? " << endl;
    cin >> input;
    switch(toupper(input)){
        case 'A':
            cout << "Added." << endl;
            player->acceptQuest(this);
            break;
        case 'N':
            cout << "Ignored." << endl;
            break;
    }
    cout << "Press ENTER to continue..." << endl;
    cin.ignore();
    cin.get();
}
int Quest::getQuestGiverX(){
    return questGiverX;
}
int Quest::getQuestGiverY(){
    return questGiverY;
}

QuestGiven Quest::getQuestInfo() {
    return questInfo;
}

void Quest::setQuestStatus(enum Status Stat) {
    questInfo.status = Stat;
}
string Quest::getQuestStatus() {
    switch(questInfo.status){
        case 0:
            return "Not Accepted";
        case 1:
            return "Pending";
        default:
            return "Completed";
    }
}
