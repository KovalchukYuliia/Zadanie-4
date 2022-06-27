#pragma once
#include <iostream>
#include <stdint.h>
#include <string>
#include <ctime>
#include <fstream>
#include <sstream>
#include "logger.hpp"

struct berResults {
	double totalBits;
	double errorBits;
	float ber;
	clock_t startTime;
	clock_t endTime;
};

class BinaryOps {
public:
	static void calculateBER(std::string file1, std::string file2);
	static void printBERResults(berResults results);
private:
	static uint8_t calculateHammingDistance(uint8_t bin1, uint8_t bin2);
};