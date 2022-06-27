#include "fileGenerator.hpp"
#include "binaryOps.hpp"

void FileGenerator::generateFile(const std::string name, const char value, const int count)
{
    std::ofstream file;
    file.open(name.c_str(), std::ios::binary);

    if (file.good())
    {
        for (int i = 0; i < count; i++)
        {
            file.write((char*)&value, 1);
        }

        file.close();

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        std::cout << "  Successsfully generated '" + name + "'." << std::endl;
        Logger::saveLog("Successsfully generated '" + name + "'.");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    }
    else {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        std::cout << "  Error occured while generating '" + name + "'." << std::endl;
        Logger::saveLog("Error occured while generating '" + name + "'.");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    }
}

char* FileGenerator::getRandomBits(const int count)
{
    srand((unsigned)time(NULL));
    int random = rand() % 5 + 2;
    std::string suffix = std::to_string((count / random) + random);
    std::string stringValue = "0x" + suffix;
    char* charValue = new char[5];
    strcpy_s(charValue, 5, stringValue.c_str());
    return charValue;
}

void FileGenerator::generateRandomFile(const std::string name, const char value, const int count)
{
    std::ofstream file;
    char* randomValue = new char[5];
    strcpy_s(randomValue, 5, getRandomBits(count));
    file.open(name.c_str(), std::ios::binary);

    if (file.good())
    {
        for (int i = 0; i < count; i++)
        {
            if (i % 10 == 0)
            {
                file.write((char*)&randomValue, 1);
            }
            else {
                file.write((char*)&value, 1);
            }
        }

        file.close();

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        std::cout << "  Successsfully generated '" + name + "'." << std::endl;
        Logger::saveLog("Successsfully generated '" + name + "'.");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    }
    else {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        std::cout << "  Error occured generating '" + name + "'." << std::endl;
        Logger::saveLog("Error occured generating '" + name + "'.");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    }
}

void FileGenerator::generateTestFiles()
{
    // test 1
    std::cout << "  Generating 'test1_file1.bin'..." << std::endl;
    Logger::saveLog("Generating 'test1_file1.bin'...");
    FileGenerator::generateFile("test1_file1.bin", 0x55, 100);
    Sleep(500);
    std::cout << "  Generating 'test1_file2.bin'..." << std::endl;
    Logger::saveLog("Generating 'test1_file2.bin'...");
    FileGenerator::generateFile("test1_file2.bin", 0x55, 100);
    Sleep(500);

    // test 2
    std::cout << "  Generating 'test2_file1.bin'..." << std::endl;
    Logger::saveLog("Generating 'test2_file1.bin'...");
    FileGenerator::generateFile("test2_file1.bin", 0x55, 100);
    Sleep(500);
    std::cout << "  Generating 'test2_file2.bin'..." << std::endl;
    Logger::saveLog("Generating 'test2_file2.bin'...");
    FileGenerator::generateRandomFile("test2_file2.bin", 0x55, 100);
    Sleep(500);

    // test 3
    std::cout << "  Generating 'test3_file1.bin'..." << std::endl;
    Logger::saveLog("Generating 'test3_file1.bin'...");
    FileGenerator::generateFile("test3_file1.bin", 0x55, 400000000);
    Sleep(500);
    std::cout << "  Generating 'test3_file2.bin'..." << std::endl;
    Logger::saveLog("Generating 'test3_file2.bin'...");
    FileGenerator::generateFile("test3_file2.bin", 0x50, 400000000);
    Sleep(500);
}