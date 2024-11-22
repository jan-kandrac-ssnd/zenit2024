#include <iostream>

using namespace std;

int main() {
    int number;
    cin >> number;
    cout << (number % 2 ? number - 1 : number + 1) << endl;
    return 0;
}