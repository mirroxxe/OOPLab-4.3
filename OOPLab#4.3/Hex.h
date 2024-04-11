#pragma once
#include "Array.h"

class Hex : public Array {
public:
    Hex(int s, unsigned char initialValue = 0);

    Hex operator+(const Hex& other) const;
    Hex operator-(const Hex& other) const;
    bool operator==(const Hex& other) const;
    bool operator!=(const Hex& other) const;

    void add(Array& other);

    friend std::ostream& operator<<(std::ostream& os, const Hex& hex);
};