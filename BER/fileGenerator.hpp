#pragma once
#include <string>
#include <fstream>
#include <Windows.h>

class FileGenerator {
public:
	static void generateFile(const std::string name, const char value, const int count);
	static void generateTestFiles();
	static void generateRandomFile(const std::string name, const char value, const int count);
	static char* getRandomBits(const int count);
};