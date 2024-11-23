#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n,k;

    cin >> n >> k;

    int weights[n];
    int values[n];

    for (int i = 0; i < n; i++) { cin >> weights[i] >> values[i]; }

    int dp[k + 1];
    for (int i = 0; i <= k; i++) dp[i] = 0;

    for (int i = 0; i < n; ++i) {
        for (int w = k; w >= 0; --w) {
            for (int c = 2; c * weights[i] <= w; ++c) {
                dp[w] = max(dp[w], dp[w - c * weights[i]] + c * values[i]);
            }
        }
    }

    cout << dp[k] << endl;

    return 0;
}