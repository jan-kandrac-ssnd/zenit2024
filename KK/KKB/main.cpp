#include <iostream>

using namespace std;

int main() {
    long long input;
    long long result = 0L;
    cin >> input;
    for (int i = 0; i < 64; i += 2) {
        result |= (input & 1ll << i + 1) >> 1;
        result |= (input & 1ll << i) << 1;
    }
    cout << result << endl;
    return 0;
}