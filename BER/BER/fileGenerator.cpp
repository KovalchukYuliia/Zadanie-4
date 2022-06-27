#include "fileGenerator.hpp"

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
    }
}