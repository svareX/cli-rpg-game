//
// Created by stepa on 28.11.2023.
//

#ifndef GAMERPG_BORDEREXCEPTION_H
#define GAMERPG_BORDEREXCEPTION_H

#include <exception>
#include <string>

class BorderException : public std::exception {
public:
    std::string body ();
};

#endif //GAMERPG_BORDEREXCEPTION_H
