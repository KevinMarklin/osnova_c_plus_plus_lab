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
    cout << "Введите размер массива:"; cin >> size;

    if (size < 0) {
        cout << "Размер массива должен быть больше нуля" << endl;
        return 0;
    }

    vector<int> massiv(size);

    cout << " Введите " << size << " элементов в массиве через пробел: " << endl;
    for (int i = 0; i < size; i++) {
        cin >> massiv[i];
    }

    sort(massiv.begin(), massiv.end());

    int target;
    cout << "Введите число, которое хотите найти:"; cin >> target;

    int left = 0;
    int right = massiv.size() - 1;
    int found_index = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (massiv[mid] == target) {
            found_index = mid;
            break;
        } 
        else if (massiv[mid] < target) {
            left = mid + 1; 
        } 
        else {
            right = mid - 1; 
        }
    }

    if (found_index != -1) {
        cout << "Элемент найден! Его индекс в отсортированном массиве: " << found_index << endl;
    } else {
        cout << "Элемент не найден в массиве." << endl;
    }

    return 0;
}