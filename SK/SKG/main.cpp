#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    long vozne[n];
    for (int i = 0; i < n; i++) {
        cin >> vozne[i];
    }
    if (n % 2 == 0 || n == 1) {
        cout << -1 << endl;
        return 0;
    }

    int pointera = n - 2;
    int pointerb = n - 1;

    long sum = 0;
    for (int i = 0; i < n / 2; i++) {
        long maximum = max(vozne[pointera], vozne[pointerb]);
        sum += maximum;
        vozne[pointera / 2] = max(0L, vozne[pointera / 2] - maximum);
        vozne[pointera] = 0;    // nepotrebne
        vozne[pointerb] = 0;    // nepotrebne

        pointera -= 2;
        pointerb -= 2;
    }

    sum += vozne[0];

    cout << sum << endl;
    return 0;
}
