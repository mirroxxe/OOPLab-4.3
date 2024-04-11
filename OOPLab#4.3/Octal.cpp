#include "Octal.h"
#include <iostream>
#include <iomanip>

Octal::Octal(int s, unsigned char initialValue) : Array(s, initialValue) {}

Octal Octal::operator+(const Octal& other) const {
    Octal result(size);
    int carry = 0;
    for (int i = size - 1; i >= 0; --i) {
        int sum = data[i] + other.data[i] + carry;
        result[i] = sum % 8;
        carry = sum / 8;
    }
    return result;
}

Octal Octal::operator-(const Octal& other) const {
    Octal result(size);
    int borrow = 0;
    for (int i = size - 1; i >= 0; --i) {
        int diff = data[i] - other.data[i] - borrow;
        if (diff < 0) {
            diff += 8;
            borrow = 1;
        }
        else {
            borrow = 0;
        }
        result[i] = diff;
    }
    return result;
}

bool Octal::operator==(const Octal& other) const {
    for (int i = 0; i < size; ++i) {
        if (data[i] != other.data[i]) {
            return false;
        }
    }
    return true;
}

bool Octal::operator!=(const Octal& other) const {
    return !(*this == other);
}

std::ostream& operator<<(std::ostream& os, const Octal& octal) {
    for (int i = 0; i < octal.size; ++i) {
        os << std::oct << static_cast<int>(octal.data[i]) << ' ';
    }
    return os;
}

void Octal::add(Array& other) {
    std::cout << "Octal addition\n";
}