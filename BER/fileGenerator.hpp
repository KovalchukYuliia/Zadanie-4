#pragma once
#include <string>
#include <fstream>

class FileGenerator {
public:
	static void generateFile(const std::string name, const char value, const int count);
};