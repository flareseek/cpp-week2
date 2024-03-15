#include <iostream>
#include <random>

extern int strikes;
extern int balls;

void getNumbers(int array[], int size);
void getAnswerNumbers(int array[], int SIZE);
void getUserNumbers(int arrya[], int SIZE);
void setScores(int userNumbers[], int answerNumbers[], int size);
void printStatus(int SIZE);

void play(int SIZE) {
    int answerNumbers[SIZE], userNumbers[SIZE];
    getAnswerNumbers(answerNumbers, SIZE);

    while (strikes < SIZE) {
        getUserNumbers(userNumbers, SIZE);
        setScores(userNumbers, answerNumbers, SIZE);
        printStatus(SIZE);
    }
}

void getAnswerNumbers(int answerNumbers[], int SIZE) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, 9);
    for(int index = 0; index < SIZE; index++) {
        int number = dis(gen);
        answerNumbers[index] = number;
    }
    
    std::cout << "Answer is ";
    for(int index = 0; index < SIZE; index++) {
        std::cout << answerNumbers[index];
    }

    std::cout << std::endl;
}

void getUserNumbers(int array[], int SIZE) {
    std::cout << "Enter a guess: ";
    getNumbers(array, SIZE);
}

void setScores(int userNumbers[], int answerNumbers[], int size) {
    int _strikes = 0, _balls = 0;
    for (int userNumberIndex = 0; userNumberIndex < size; userNumberIndex++) {
        const int currentUserNumber = userNumbers[userNumberIndex];

        if (currentUserNumber == answerNumbers[userNumberIndex]) {
            _strikes++;
            continue;
        }

        for (int answerNumberIndex = 0; answerNumberIndex < size; answerNumberIndex++) {
            if (answerNumberIndex == userNumberIndex) continue;

            const int currentAnswerNumber = answerNumbers[answerNumberIndex];
            if (currentAnswerNumber != currentUserNumber) continue;
            _balls++;
            break;
        }
    }
    strikes = _strikes;
    balls = _balls;
}

void printStatus(int SIZE) {
    if (strikes == SIZE) std::cout << "You win!" << std::endl;
    else std::cout << "Strikes: " << strikes << ", " << "Balls: " << balls << std::endl;
}