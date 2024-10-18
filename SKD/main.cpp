#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int grid[n][n];
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            cin >> grid[y][x];
        }
    }

    for (int riadok = 0; riadok < n - 1; riadok++) {
        for (int stlpec = 0; stlpec < n - 1; stlpec++) {
            if (grid[riadok][stlpec] != grid[riadok + 1][stlpec + 1]) {
                cout << "kopa smetia" << endl;
                return 0;
            }
        }
    }

    cout << "dokonale diagonalne" << endl;

    return 0;
}
