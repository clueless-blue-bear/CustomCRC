#include <iostream>
#include <vector>
#include <cstddef>
#include "FileOperations.hpp"
#include "BitOperations.hpp"

int main()
{
    std::vector<uint8_t> inputVector;
    std::string fileName;

    std::cout << "Please input name of the file you want to read into the buffer: \n";
    std::cin >> fileName;
    
    ReadFile(fileName, inputVector);

    for (int j = 0; j < inputVector.size(); j++) {
        for(int i = 7; i >= 0; i--){
        char bit = ExtractBit(i, inputVector[j]) ? '1' : '0';
        std::cout << bit;
        }
        std::cout << '\n';
    }
}