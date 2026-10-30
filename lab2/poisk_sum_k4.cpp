#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <windows.h>

using namespace std;

int main() {

    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int n = 1000000;
    vector<int> arr(n);

    mt19937 gen(random_device{}());
    uniform_int_distribution<> dist(1, 1000);

    generate(arr.begin(), arr.end(), [&]() { 
        return dist(gen); 
    });

    int k;
    cout << "Введите число K: ";
    cin >> k;


    int last_index[1001];
    for (int i = 0; i <= 1000; i++) {
        last_index[i] = -1;
    }

    bool found = false;

    for (int i = 0; i < n; i++) {
        int need = k - arr[i]; // Число, которое нужно найти в пару

        // Проверяем, существует ли подходящее число в диапазоне от 1 до 1000
        // и встречалось ли оно нам ранее
        if (need >= 1 && need <= 1000 && last_index[need] != -1) {
            cout << "Найдена пара!\n";
            cout << "Индексы: " << last_index[need] << " и " << i << "\n";
            cout << "Числа: " << need << " + " << arr[i] << " = " << k << "\n";
            found = true;
            break;
        }

        // Запоминаем текущее число и его индекс
        last_index[arr[i]] = i;
    }

    if (!found) {
        cout << "Пара с такой суммой не найдена.\n";
    }

    return 0;
}