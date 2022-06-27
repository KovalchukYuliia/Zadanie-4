#include "binaryOps.hpp"
#include "fileGenerator.hpp"

int main(int argc, char *argv[])
{
    std::string file1, file2;
    berResults results;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

    if (argc != 3)
    {
        std::cout << "No file names were provided." << std::endl;
        Sleep(1000);
        std::cout << "Generating test files..." << std::endl;
        FileGenerator::generateTestFiles();
        std::cout << "The generating has been completed.\nRe-run the program using the given arguments: './ber.exe test#_file1.bin test#_file2.bin'." << std::endl;
    }
    else
    {
        file1 = argv[1];
        file2 = argv[2];

        BinaryOps::calculateBER(file1, file2);
    }

    exit(0);
}