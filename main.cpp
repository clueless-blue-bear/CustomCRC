#include <iostream>
#include <vector>
#include <cstddef>
#include <algorithm>
#include <cstdint>
#include "FileOperations.hpp"
#include "BitOperations.hpp"

int main()
{
    std::vector<uint8_t> mainBuffer;
    std::string fileName;

    std::cout << "Please input name of the file you want to read into the buffer: \n";
    std::cin >> fileName;
    
    ReadFile(fileName, mainBuffer);
    auto bits = ConvertToVectorOfBits(mainBuffer);
    for (auto a: bits) {
        char bit = (bool)a? '1':'0';
        std::cout << bit;
    }

    std::cout << '\n';
    return 0; 
}