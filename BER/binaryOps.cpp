#include "binaryOps.hpp"

uint8_t BinaryOps::calculateHammingDistance(uint8_t n1, uint8_t n2)
{
    uint8_t x = n1 ^ n2;
    uint8_t setBits = 0;

    while (x > 0)
    {
        setBits += x & 1;
        x >>= 1;
    }

    return setBits;
}

void BinaryOps::calculateBER(std::string _file1, std::string _file2)
{
    std::ifstream file1, file2;
    berResults results;
    results.totalBits = 0;
    results.errorBits = 0;
    results.ber = 0;
    results.startTime = 0;
    results.endTime = 0;

    std::cout << "Calculating BER..." << std::endl;
    Logger::saveLog("Calculating BER...");
    file1.open(_file1.c_str(), std::ios::binary);
    file2.open(_file2.c_str(), std::ios::binary);
    char a = 0x00;
    char b = 0x00;
    results.startTime = clock();

    while (!file1.eof())
    {
        file1 >> a;
        file2 >> b;

        if (!file1.eof())
        {
            results.errorBits += calculateHammingDistance(a, b);
            results.totalBits += 8;
        }
    }

    results.ber = ((float)results.errorBits / results.totalBits);
    results.endTime = clock();
    std::cout << "BER calculation has been completed.\n" << std::endl;
    Logger::saveLog("BER calculation has been completed.");
    BinaryOps::printBERResults(results);
}

void BinaryOps::printBERResults(berResults results)
{
    std::stringstream ss;
    ss << "RESULTS" << std::endl;
    ss << " Number of total bits: " << results.totalBits << std::endl;
    ss << " Number of error bits: " << results.errorBits << std::endl;
    ss << " BER result: " << results.ber << std::endl;
    ss << " Calculation time: " << (((float)results.endTime - results.startTime) / CLOCKS_PER_SEC) << "s";
    std::cout << ss.str() << std::endl;
    Logger::saveLog(ss.str());
}