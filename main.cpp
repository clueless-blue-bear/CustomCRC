#include <iostream>
#include <fstream>
#include <vector>
#include <cstddef>


void readFile(const std::string& fileName, std::vector<uint8_t> &inputVector) {
    std::ifstream inputFile { "test.bin", std::ios::binary };
    size_t size;

    if(inputFile){
        inputFile.seekg(0, inputFile.end);
        size_t end = inputFile.tellg();
        inputFile.seekg(0, inputFile.beg);
        size = end - inputFile.tellg();
        std::cout << "size: " << size << '\n';  // dodatek
        
        // reserv vec
        inputVector.resize(size);

        inputFile.read(reinterpret_cast<char*>(inputVector.data()), size);

        inputFile.close();
    }
}

uint8_t ExtractBit(uint8_t bit, uint8_t byte) {
    return (byte >> (bit % 8)) & 1;
}

uint8_t ExtractNBits(uint8_t bit_beg, uint8_t bit_end, uint8_t byte) {
    auto mask = ((1 << (bit_end - bit_beg)) - 1) << bit_beg;
    auto x = byte & mask;
   
    return x;
}

int main()
{
    std::vector<uint8_t> inputVector;
    std::string fileName;

    std::cout << "Give file name: \n";
    //std::cin >> fileName;
    
    readFile("test.bin", inputVector);

    for(int i = 7; i >= 0; i--){
        char bit = ExtractBit(i, inputVector[0]) ? '1' : '0';
        std::cout << bit;
    }

    std::ofstream of{ "a.bin", std::ios::binary };
    uint8_t wyni = ExtractNBits(2, 3, inputVector[0]);
    
    std::vector<uint8_t> we{ wyni };
    of.write((char*)we.data(), 1);
    of.close();
}