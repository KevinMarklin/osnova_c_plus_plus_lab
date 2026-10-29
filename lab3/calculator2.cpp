#include <iostream>
#include <string>
#include <windows.h>
#include <iomanip>
#include <algorithm>
using namespace std;
#include <cctype>
#include <vector>
#include <sstream>



double calculate(double a, double b, char op) {

    if (op == '+') {
        return a + b; 
    }

    if (op == '-') {
        return a - b; 
    }

    if (op == '/') {
        return a / b; 
    }

    if (op == '*') {
        return a * b; 
    }

    return 0;

}



int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int num1;
    int num2;
    char deystvie;

    cout << "Введите первое число:"; cin >> num1;
    cout << "Введите второе число:"; cin >> num2;
    cout << "Введите знак действи(+, -, /, *):"; cin >> deystvie;

    if (deystvie == '+' || deystvie == '-' || deystvie == '*' || deystvie == '/') {

        double result = calculate(num1, num2, deystvie);
        cout << " Ответ " << result << endl;
    }
    else {

        cout << "Знак должен быть один из (+, -, /, *)" << endl;
        return 0;
    }

    return 0;

}