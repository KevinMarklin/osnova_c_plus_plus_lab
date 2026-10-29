#include <iostream>
#include <string>
#include <windows.h>
#include <iomanip>
#include <algorithm>
using namespace std;
#include <cctype>
#include <vector>
#include <sstream>


int main() {

    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int size;
    cout << "Введите размер массива: "; cin >> size;

    if (size <= 0) {
        cout << "Размер массива должен быть больше нуля!" << endl;
        return 0;
    }


    vector<int> massiv(size);
    string line;

    cout << "Введите " << size << " элементов массива через пробел:" << endl;
    for (int i = 0; i < size; i++) {
        cin >> massiv[i];
    }


    if (massiv.empty()) {
        cout << "Массив пуст!" << endl;
        return 0;
    }


    for (size_t j = 0; j < massiv.size() - 1; j++) {
        for (size_t i = 0; i < massiv.size() - 1; i++) {
            if (massiv[i] > massiv[i + 1]) {
                
                int temp = massiv[i];
                massiv[i] = massiv[i + 1];
                massiv[i + 1] = temp;
                
            }
        }
    }

    cout << "Отсортированный массив:";
    for (int num : massiv) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}














