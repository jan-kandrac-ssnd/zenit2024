#include <iostream>
#include <algorithm>

using namespace std;

string toDragonNumber(int n) {
    string dragonNumber;
    while (n != 0) {
        switch (n % 3) {
            case 0: dragonNumber += '0'; break;
            case 1: dragonNumber += '+'; break;
            case 2: dragonNumber += '-'; n++; break;
            default: ;
        }
        n /= 3;
    }
    reverse(dragonNumber.begin(), dragonNumber.end());
    return dragonNumber.empty() ? "0" : dragonNumber;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        cout << toDragonNumber(input) << endl;
    }
    return 0;
}
