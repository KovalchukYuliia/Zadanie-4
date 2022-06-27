#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include <chrono>

class Logger {
public:
	static void openLog(std::string fileName);
	static void saveLog(std::string msg);
	static void closeLog();

private:
	static std::string getFormattedTimestamp();
	static double getTimestamp();
};