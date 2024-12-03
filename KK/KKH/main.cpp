#include <iostream>
#include <numeric>

using namespace std;

int main() {
    long m, n;
    cin >> m >> n;
    const long a = m / gcd(m, n);
    const long b = n / gcd(m, n);
    const long result = (8 * a) + (b - a) * 4 - 8;
    cout << result << endl;
    return 0;
}