#include <iostream>
#include <vector>
#include <windows.h>





using namespace std;

int main() {

    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int matrix[10][10] = {
        {9, 8, 7, 8, 9, 9, 8, 7, 8, 9},
        {8, 2, 8, 9, 8, 7, 6, 7, 8, 9},
        {7, 8, 7, 8, 9, 8, 5, 8, 9, 8},
        {8, 9, 8, 1, 8, 9, 8, 9, 8, 7},
        {9, 8, 9, 8, 7, 8, 9, 8, 7, 8},
        {8, 7, 6, 7, 8, 3, 8, 7, 6, 7},
        {7, 6, 1, 6, 7, 8, 7, 6, 5, 6},
        {8, 7, 6, 7, 8, 9, 8, 7, 4, 7},
        {9, 8, 7, 8, 9, 8, 7, 6, 7, 8},
        {8, 9, 8, 9, 8, 7, 6, 7, 8, 9}
    };

    vector<int> result;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            bool is_min = true;

            for (int di = -1; di <= 1; di++) {
                for (int dj = -1; dj <= 1; dj++) {
                    if (di == 0 && dj == 0) continue;

                    int ni = i + di;
                    int nj = j + dj;

                    if (ni >= 0 && ni < 10 && nj >= 0 && nj < 10) {
                        if (matrix[i][j] >= matrix[ni][nj]) {
                            is_min = false;
                            break;
                        }
                    }
                }
                if (!is_min) break;
            }

            if (is_min) {
                result.push_back(matrix[i][j]);
                cout << "Локальный минимум: " << matrix[i][j] 
                     << " на позиции [" << i << "][" << j << "]\n";
            }
        }
    }

    return 0;
}