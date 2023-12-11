//
// Created by stepa on 02.12.2023.
//

#include "../../include/exceptions/GameOverException.h"

std::string GameOverException::body() {
    return "You have died!";
}
