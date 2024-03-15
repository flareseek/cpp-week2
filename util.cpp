#include <iostream>

void getNumbers(int array[], int size) {
    int inputNumber = 0;
    std::cin >> inputNumber;
    for (int index = size - 1; index >= 0; index--) {
        array[index] = inputNumber % 10;
        inputNumber /= 10;
    }
}