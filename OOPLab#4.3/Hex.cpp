#include "Hex.h"
#include <iostream>
#include <iomanip>

Hex::Hex(int s, unsigned char initialValue) : Array(s, initialValue) {}

Hex Hex::operator+(const Hex& other) const {
    Hex result(size);
    int carry = 0;
    for (int i = size - 1; i >= 0; --i) {
        int sum = data[i] + other.data[i] + carry;
        result[i] = sum % 16;
        carry = sum / 16; 
    }
    if (carry != 0) {
        std::cerr << "Overflow occurred during addition\n";
    }
    return result;
}

Hex Hex::operator-(const Hex& other) const {
    Hex result(size);
    int borrow = 0;
    for (int i = size - 1; i >= 0; --i) {
        int diff = data[i] - other.data[i] - borrow;
        if (diff < 0) {
            diff += 16;
            borrow = 1;
        }
        else {
            borrow = 0;
        }
        result[i] = diff;
    }
    return result;
}

bool Hex::operator==(const Hex& other) const {
    for (int i = 0; i < size; ++i) {
        if (data[i] != other.data[i]) {
            return false;
        }
    }
    return true;
}

bool Hex::operator!=(const Hex& other) const {
    return !(*this == other);
}

std::ostream& operator<<(std::ostream& os, const Hex& hex) {
    for (int i = 0; i < hex.size; ++i) {
        os << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(hex.data[i]) << ' ';
    }
    return os;
}

void Hex::add(Array& other) {
    std::cout << "Hex addition\n";
}