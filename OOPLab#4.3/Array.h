#pragma once

#include <iostream>
#include <iomanip>
#include <vector>

const int MAX_SIZE = 100;

class Array {
protected:
    std::vector<unsigned char> data;
    int size;

public:
    Array(int s, unsigned char initialValue = 0);
    virtual ~Array() {}

    unsigned char& operator[](int index);
    virtual void add(Array& other);
    void rangeCheck(int index);
};