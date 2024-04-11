#pragma once
#include "Array.h"

class Octal : public Array {
public:
    Octal(int s, unsigned char initialValue = 0);

    Octal operator+(const Octal& other) const;
    Octal operator-(const Octal& other) const;
    bool operator==(const Octal& other) const;
    bool operator!=(const Octal& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Octal& octal);

    void add(Array& other) override;
};