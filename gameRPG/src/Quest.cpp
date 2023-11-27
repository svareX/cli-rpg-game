//
// Created by temel on 24.11.2023.
//

#include "../include/Quest.h"
#include "../include/Map.h"
#include <vector>
#include <cstdlib>

QuestGiven test[2] = {{"Ahoj.", 50},
                      {"Zdravicko.", 100}};

using namespace std;
Quest::Quest(Map& gameMap): map(gameMap){
    questGiverX = 2;
    questGiverY = 2; //X & Y will be random generated in future
    int random = rand()%sizeof(test-1);
    quest = test[random];
    map.gameMap[questGiverY][questGiverX] = 'Q';
}

void Quest::displayQuest(){
    system("cls");
    char input;
    cout << quest.task << " " << quest.goldAmount << endl;
    cout << "Do you wanna add this quest to quest list? " << endl;
    cin >> input;
    switch(toupper(input)){
        case 'A':
            cout << "Added." << endl;
            break;
        case 'N':
            cout << "Ignored." << endl;
            break;
    }
    cin.ignore();
    cin.get();
}
