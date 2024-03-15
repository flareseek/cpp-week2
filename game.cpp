#include <iostream>

void getNumbers(int array[], int size);
void getAnswerNumbers(int array[], int SIZE);

void play(int SIZE) {
    int answerNumbers[SIZE];
    getAnswerNumbers(answerNumbers, SIZE);
}

void getAnswerNumbers(int array[], int SIZE) {
    std::cout << "Enter a answer: ";
    getNumbers(array, SIZE);
}