
#include <iostream>
#include <fstream>
#include <string>

int main(int ac, char *av[])
{
    if (ac != 4)
    {
        std::cout << "Usage: ./program <filename> <s1> <s2>" << std::endl;
        return 1;
    }
    std::string file = av[1];
    std::string s1 = av[2];
    std::string s2 = av[3];
    std::ifstream inputFile(file.c_str());
    if (!inputFile.is_open())
    {
        std::cerr << "Error: could not open input file." << std::endl;
        return 2;
    }
    std::ofstream outputFile((file + ".replace").c_str());
    if (!outputFile.is_open())
    {
        std::cerr << "Error: could not create output file." << std::endl;
        return 3;
    }
    size_t pos;
    std::string line;
    while (std::getline(inputFile, line))
    {
        pos = 0;
        while ((pos = line.find(s1, pos)) != std::string::npos)
        {
            line.erase(pos, s1.length());
            line.insert(pos, s2);
            pos += s2.length();
        }
        outputFile << line << std::endl;
    }
    inputFile.close();
    outputFile.close();
    return 0;
}
