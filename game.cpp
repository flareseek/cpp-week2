#include <iostream>

extern int strikes;
extern int balls;

void getNumbers(int array[], int size);
void getAnswerNumbers(int array[], int SIZE);

void play(int SIZE) {
    int answerNumbers[SIZE], userNumbers[SIZE];
    getAnswerNumbers(answerNumbers, SIZE);

    while (strikes < SIZE) {
        getUserNumbers(userNumbers, SIZE);
    }
}

void getAnswerNumbers(int array[], int SIZE) {
    std::cout << "Enter a answer: ";
    getNumbers(array, SIZE);
}

void getUserNumbers(int array[], int SIZE) {
    std::cout << "Enter a guess: ";
    getNumbers(array, SIZE);
}