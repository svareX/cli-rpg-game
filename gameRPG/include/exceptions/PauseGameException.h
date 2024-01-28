//
// Created by stepa on 28.01.2024.
//

#ifndef GAMERPG_PAUSEGAMEEXCEPTION_H
#define GAMERPG_PAUSEGAMEEXCEPTION_H

#include <exception>
#include <string>

class PauseGameException : public std::exception {
public:
    std::string body ();
};

#endif //GAMERPG_PAUSEGAMEEXCEPTION_H
