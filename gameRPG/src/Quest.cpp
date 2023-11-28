//
// Created by temel on 24.11.2023.
//

#include "../include/Quest.h"
#include "../include/Map.h"
#include <vector>
#include <cstdlib>

const char* boldOn = "\033[1m";
const char* boldOff = "\033[0m";

QuestGiven test[2] = {{"Hello, can you please bring me my AMULET? I lost it somewhere in the forest.", 50, },
                      {"Good evening, can you please help me find my sacred AXE? I will pay you accordingly.", 100}};

using namespace std;
Quest::Quest(Map& gameMap): map(gameMap){
    int rndX = rand()% map_size;
    int rndY = rand()% map_size;
    questGiverX = rndX;
    questGiverY = rndY;
    int arraySize = sizeof(test) / sizeof(test[0]);
    int random = rand()%arraySize;
    questInfo = test[random];
    questInfo.status = NotAccepted;
    test[random] = test[arraySize-1];
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
