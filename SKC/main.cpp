#include <iostream>

using namespace std;

int main() {
    string line;
    getline(cin, line);
    cout << ((line.length() - 9) / 10) << endl;
    return 0;
}