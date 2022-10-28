#include <vector>
#include <cstdint>
#include <vector>

uint8_t ExtractBit(uint8_t bit, uint8_t byte) {
    return (byte >> (bit % 8)) & 1;
}

uint8_t ExtractNBits(uint8_t bit_beg, uint8_t bit_end, uint8_t byte) {
    auto mask = ((1 << (bit_end - bit_beg)) - 1) << bit_beg;
    auto x = byte & mask;
   
    return x;
}

uint8_t crc8_generator = 0xD5;

void CRC8 (std::vector<uint8_t>& buffer) {
    uint8_t registry = 0x00;
    buffer.resize(buffer.size() + 1);

    while (buffer.size() > 0) {
        uint8_t byte = buffer.at(0);
    }
}

std::vector<uint8_t> ConvertToVectorOfBits (std::vector<uint8_t>& buffer) {
    std::vector<uint8_t> result;
    uint8_t byte;

    for (auto byte: buffer) {
        for (int i = 7; i >= 0; i--) {
            result.push_back(ExtractBit(i,byte));
        }
    }
    return result;
}