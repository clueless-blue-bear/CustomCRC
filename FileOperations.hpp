#include <vector>
#include <fstream>
#include <cstdint>

/*Reads entire file into a vector of uint8_t type, by using fstream::read and reinterpret cast*/
void ReadFile(const std::string& fileName, std::vector<uint8_t> &inputVector) {
    std::ifstream inputFile { fileName, std::ios::binary };
    size_t size;

    if(inputFile){
        inputFile.seekg(0, inputFile.end);
        size_t end = inputFile.tellg();
        inputFile.seekg(0, inputFile.beg);
        size = end - inputFile.tellg();
        
        inputVector.reserve(size);
        inputVector.resize(size);

        inputFile.read(reinterpret_cast<char*>(inputVector.data()), size);

        inputFile.close();
    }
}

// Saves the entire buffer into a binary file
void SaveFile(const std::string& fileName, std::vector<uint8_t>& buffer) {
    std::ofstream outputFile {fileName, std::ios::binary | std::ios::out};
    size_t size = buffer.size();

    if (!outputFile) { throw new std::runtime_error {"Couldn't open the binary output file"}; }

    if (!outputFile.write(reinterpret_cast<char *>(buffer.data()), size)) {
        throw new std::runtime_error {"Error while saving buffer to file"};
    }
}