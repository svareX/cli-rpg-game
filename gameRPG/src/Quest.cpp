//
// Created by temel on 24.11.2023.
//

#include "../include/Quest.h"
#include "../include/Map.h"
#include <vector>
#include <cstdlib>

QuestGiven test[2] = {{"Hello, can you please bring me my amulet? I lost is somewhere in the forest.", 50},
                      {"Good evening to you traveller, can you please help me find my sacred axe? I will pay you accordingly.", 100}};

using namespace std;
Quest::Quest(Map& gameMap): map(gameMap){
    int rndX = rand()% map_size;
    int rndY = rand()% map_size;
    questGiverX = rndX;
    questGiverY = rndY;
    int random = rand()%sizeof(test-1);
    questInfo = test[random];
    map.addQuestToMap(this);
}

void Quest::display(){
    system("cls");
    char input;
    cout << questInfo.task << " " << questInfo.goldAmount << endl;
    cout << "Do you wanna add this quest to quest list? " << endl;
    cin >> input;
    switch(toupper(input)){
        case 'A':
            cout << "Added." << endl;
            cout << this->questInfo.task << endl;
            break;
        case 'N':
            cout << "Ignored." << endl;
            break;
    }
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
