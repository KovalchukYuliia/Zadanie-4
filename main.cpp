#include <iostream>
#include "binaryOps.hpp"

int main()
{
    std::cout << "Bit Error Rate" << std::endl;
    std::cout << "----------------------------------" << std::endl;
    std::cout << int(BinaryOps::calculateHammingDistance(0xFF, 0xFE)) << std::endl;
}