#ifndef GAMERPG_LOGGER_H
#define GAMERPG_LOGGER_H

#include <iostream>
#include <fstream>

class Logger {
public:
    static Logger& getInstance();

    void log(const std::string& message);

private:
    Logger();
    ~Logger();

    static Logger m_instance;
    std::ofstream m_logFile;
};

#endif //GAMERPG_LOGGER_H
