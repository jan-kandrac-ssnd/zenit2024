#include <iostream>

using namespace std;

int help(const int& i) {
    if (i == 1) return 5;
    if (i == 2) return 6;
    if (i % 2 == 1) return help(i - 1) * 5;
    return help(i - 2) * 7;
}

int main() {
    int n;
    cin >> n;
    cout << help(n) << endl;
    return 0;
}