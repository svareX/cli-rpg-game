//
// Created by stepa on 28.01.2024.
//

#include "../../include/exceptions/PauseGameException.h"

std::string PauseGameException::body() {
    return "Game has been paused!";
}
