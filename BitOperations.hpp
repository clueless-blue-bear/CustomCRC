#include <vector>
#include <cstdint>

uint8_t ExtractBit(uint8_t bit, uint8_t byte) {
    return (byte >> (bit % 8)) & 1;
}

uint8_t ExtractNBits(uint8_t bit_beg, uint8_t bit_end, uint8_t byte) {
    auto mask = ((1 << (bit_end - bit_beg)) - 1) << bit_beg;
    auto x = byte & mask;
   
    return x;
}