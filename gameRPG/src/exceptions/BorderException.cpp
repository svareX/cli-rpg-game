//
// Created by stepa on 28.11.2023.
//

#include "../../include/exceptions/BorderException.h"

std::string BorderException::body() {
    return "You cannot go past the game borders!";
}
