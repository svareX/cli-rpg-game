//
// Created by stepa on 02.12.2023.
//

#ifndef GAMERPG_GAMEOVEREXCEPTION_H
#define GAMERPG_GAMEOVEREXCEPTION_H

#include <exception>
#include <string>

class GameOverException : public std::exception {
public:
    std::string body ();
};
#endif //GAMERPG_GAMEOVEREXCEPTION_H
