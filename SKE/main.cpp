#include <iostream>
#include <stack>

using namespace std;

bool can(const long &remainder) {
    stack<long> remaining;
    remaining.push(remainder);
    while (!remaining.empty()) {
        const long solve = remaining.top();
        remaining.pop();
        if (solve < 0) continue;
        if (solve % 5 == 0 || solve % 7 == 0 || solve % 13 == 0) return true;
        remaining.push(solve - 5);
        remaining.push(solve - 7);
        remaining.push(solve - 13);
    }
    return false;
}

int main() {
    int n;
    long input;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> input;
        if (can(input)) {
            cout << "ANO" << endl;
        } else {
            cout << "NIE" << endl;
        }
    }
    return 0;
}