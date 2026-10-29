#include <iostream>
#include <string>
#include <windows.h>
#include <iomanip>
#include <algorithm>
using namespace std;
#include <cctype>
#include <vector>
#include <sstream>


int maxOfThree(int a, int b, int c) {
    
    int max_number = a;

    if (b > max_number) {
        max_number = b; 
    }

    if (c > max_number) {
        max_number = c; 
    }

    return max_number;
}


int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int num1;
    int num2;
    int num3;

    cout << "Введите первое число:"; cin >> num1;
    cout << "Введите второе число:"; cin >> num2;
    cout << "Введите третье число:"; cin >> num3;

    int result = maxOfThree(num1, num2, num3);

    cout << " Максимальное число:" << result << endl;

}