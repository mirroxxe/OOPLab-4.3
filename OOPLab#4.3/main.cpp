#include <iostream>
#include "Hex.h"
#include "Octal.h"

void hexOperations() {
    Hex hex1(5, 0x1F);
    Hex hex2(5, 0x10);

    std::cout << "Hex1: " << hex1 << std::endl;
    std::cout << "Hex2: " << hex2 << std::endl;

    Hex sum = hex1 + hex2;
    std::cout << "Sum: " << sum << std::endl;

    Hex difference = hex1 - hex2;
    std::cout << "Difference: " << difference << std::endl;

    if (hex1 == hex2) {
        std::cout << "Hex1 equals Hex2\n";
    }
    else {
        std::cout << "Hex1 is not equal to Hex2\n";
    }
}

void virtualFunctions() {
    Hex hexArray(5, 0x1F);
    Octal octalArray(5, 07);

    Array* baseHex = &hexArray;
    Array* baseOctal = &octalArray;

    std::cout << "Calling virtual functions:\n";
    baseHex->add(hexArray);
    baseHex->add(octalArray);

    baseOctal->add(hexArray);
    baseOctal->add(octalArray);
}

int main() {
    hexOperations();

    virtualFunctions();

    return 0;
}