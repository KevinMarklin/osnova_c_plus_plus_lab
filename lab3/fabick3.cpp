#include <iostream>
#include <windows.h>

using namespace std;

int fibonacci(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;

    int a = 0;
    int b = 1; 
    int current = 0;


    for (int i = 2; i <= n; i++) {
        current = a + b;
        a = b;           
        b = current;     
    }

    return current;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int n;
    cout << "Введите номер числа Фибоначчи (n): ";
    cin >> n;

    int result = fibonacci(n);
    cout << "Число Фибоначчи под номером " << n << " равно: " << result << endl;

    return 0;
}