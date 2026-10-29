#include <iostream>
#include <string>
#include <windows.h>
#include <random>
#include <thread>
#include <chrono>

using namespace std;

int generateSecretNumber(int min, int max) {
    random_device rd; 
    mt19937 gen(rd()); 
    uniform_int_distribution<int> dist(min, max); 
    
    return dist(gen);
}

int getPlayerGuess() {
    int guess;

    cout << "Введи число: "; cin >> guess;

    return guess;
}

void giveHint(int secret, int guess) {
    if (guess < secret) {
        cout << "Подсказка: Загаданное число БОЛЬШЕ!" << endl;
    } else if (guess > secret) {
        cout << "Подсказка: Загаданное число МЕНЬШЕ!" << endl;
    } else {
        cout << "Ура! Ты угадал!" << endl;
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    char playAgain;

    do {
        int min_range, max_range;

        cout << "\n=== ИГРА «УГАДАЙ ЧИСЛО» ===" << endl;
        cout << "Задай диапазон поиска числа:" << endl;
        cout << "Минимальное число: "; cin >> min_range; 
        cout << "Максимальное число: "; cin >> max_range;

        if (min_range >= max_range) {
            cout << "Ошибка: максимальная граница должна быть строго больше минимальной!" << endl;
            return 0;
        }

        cout << "\nТеперь я загадываю число..." << endl;
        int secretNumber = generateSecretNumber(min_range, max_range);

        this_thread::sleep_for(chrono::seconds(2));
        cout << "Загадал! Попробуй отгадать, а я буду давать подсказки." << endl;

        int attempts = 0;
        int currentGuess = 0;

        do {
            currentGuess = getPlayerGuess();
            attempts++;

            giveHint(secretNumber, currentGuess);
            cout << endl;

        } while (currentGuess != secretNumber);

        cout << "Отличная игра! Количество затраченных попыток: " << attempts << endl;

        cout << "\nХочешь сыграть еще раз? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "\nСпасибо за игру! До встречи!" << endl;

    return 0;
}