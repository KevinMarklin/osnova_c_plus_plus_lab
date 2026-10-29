#include <iostream>
#include <string>
#include <windows.h>
#include <iomanip>
#include <algorithm>
using namespace std;
#include <cctype>
#include <vector>
#include <sstream>








string encryptCaesar(string text, int shift) {
    string result = "";
    for (char c : text) {
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            int shifted = (c - base + (shift % 26)) % 26;
            result += base + shifted;
        } else {
            result += c;
        }
    }
    return result;
}


string decryptCaesar(string text, int shift) {
    string result = "";
    for (char c : text) {
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            int shifted = (c - base - (shift % 26) + 26) % 26;
            result += base + shifted;
        } else {
            result += c;
        }
    }
    return result;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);



    string secret_message;
    int shift;

    cout << "Введите послание, которое нужно зашифровать на английском языке: "; getline(cin, secret_message);
    cout << "Введите размер shift: "; cin >> shift;


    cout << "Оригинал:   " << secret_message << endl;

    string encrypted = encryptCaesar(secret_message, shift);
    cout << "Шифр:       " << encrypted << endl;

    string decrypted = decryptCaesar(encrypted, shift);
    cout << "Расшифровка: " << decrypted << endl;

    return 0;
}



