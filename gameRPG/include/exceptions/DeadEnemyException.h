//
// Created by stepa on 02.12.2023.
//

#ifndef GAMERPG_DEADENEMYEXCEPTION_H
#define GAMERPG_DEADENEMYEXCEPTION_H

#include <exception>
#include <string>

class DeadEnemyException : public std::exception {
public:
    std::string body ();
};
#endif //GAMERPG_DEADENEMYEXCEPTION_H
