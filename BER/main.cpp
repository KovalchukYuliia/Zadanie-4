#include "binaryOps.hpp"
#include "fileGenerator.hpp"
#include "logger.hpp"

int main(int argc, char *argv[])
{
    std::string file1, file2;
    berResults results;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    Logger::openLog("log.txt");

    if (argc != 3)
    {
        std::cout << "No file names were provided." << std::endl;
        Logger::saveLog("No file names were provided.");
        Sleep(1000);
        std::cout << "Generating test files..." << std::endl;
        Logger::saveLog("Generating test files...");
        FileGenerator::generateTestFiles();
        std::cout << "The generating has been completed." << std::endl;
        Logger::saveLog("The generating has been completed.");
        std::cout << "Re-run the program using the given arguments: './ber.exe test#_file1.bin test#_file2.bin'." << std::endl;
        Logger::saveLog("Re-run the program using the given arguments: './ber.exe test#_file1.bin test#_file2.bin'.");
    }
    else
    {
        file1 = argv[1];
        file2 = argv[2];

        BinaryOps::calculateBER(file1, file2);
    }

    Logger::closeLog();
    exit(0);
}