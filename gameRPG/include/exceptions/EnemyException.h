//
// Created by stepa on 28.11.2023.
//

#ifndef GAMERPG_ENEMYEXCEPTION_H
#define GAMERPG_ENEMYEXCEPTION_H

#include <exception>
#include <string>

class EnemyException : public std::exception {
public:
    std::string body ();
};

#endif //GAMERPG_ENEMYEXCEPTION_H
