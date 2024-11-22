#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int sum = 0;
    int lastPos = -1;
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        if (value == 0) continue;
        if (lastPos == -1) { lastPos = i; sum++; continue; }
        if (i == lastPos + 1) { lastPos = i; sum++; continue; }
        sum += 2;
        lastPos = i;
    }
    cout << sum << endl;
    return 0;
}
