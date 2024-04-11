#include "Array.h"
#include <iostream>

Array::Array(int s, unsigned char initialValue) : size(s), data(s, initialValue) {}

unsigned char& Array::operator[](int index) {
    rangeCheck(index);
    return data.at(index); 
}

void Array::add(Array& other) {
    std::cout << "Base class addition\n";
}

void Array::rangeCheck(int index) {
    if (index < 0 || index >= size) {
        std::cerr << "Index out of range\n";
        exit(1);
    }
}