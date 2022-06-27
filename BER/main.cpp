#include <iostream>
#include "binaryOps.hpp"
#include "fileGenerator.hpp"

int main()
{
    std::cout << "Bit Error Rate" << std::endl;
    std::cout << "----------------------------------" << std::endl;
    FileGenerator::generateFile("file1.bin", 0xFF, 100);
    FileGenerator::generateFile("file2.bin", 0xFE, 100);
    std::cout << int(BinaryOps::calculateHammingDistance(0xFF, 0xFE)) << std::endl;
}