#include "../include/Logger.h"

Logger Logger::m_instance;

Logger::Logger() {
    m_logFile.open("../log.txt", std::ios::out | std::ios::trunc);
}

Logger::~Logger() {
    m_logFile.close();
}

Logger& Logger::getInstance() {
    return m_instance;
}

void Logger::log(const std::string& message) {
    m_logFile << message << std::endl;
}