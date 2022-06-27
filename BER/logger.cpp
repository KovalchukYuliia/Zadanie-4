#include "logger.hpp"
#include <Windows.h>

std::fstream logFile;

void Logger::openLog(std::string name)
{
    logFile.open(name.c_str(), std::ios_base::app);

    if (logFile.good())
    {
        saveLog("Log file is opened");
    }
    else {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        std::cout << "Unable to open log file." << std::endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    }
}

void Logger::saveLog(std::string msg)
{
    std::string log = " " + getFormattedTimestamp() + " " + msg + "\n";
    logFile << log;
    logFile.flush();
}

void Logger::closeLog()
{
    saveLog("Log file is closed\n");
    logFile.close();
}

double Logger::getTimestamp()
{
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    return (double)std::chrono::system_clock::to_time_t(now);
}

std::string Logger::getFormattedTimestamp()
{
    time_t timestamp = (time_t)getTimestamp();
    struct tm timeinfo;
    char buffer[80];
    time(&timestamp);
    localtime_s(&timeinfo, &timestamp);
    strftime(buffer, 80, "%c", &timeinfo);
    std::string str(buffer);
    return str;
}