#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, k;
        cin >> n >> k;

        char board[n][n];

        // read
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < n; x++) {
                cin >> board[y][x];
            }
        }

        // slide right
        for (int y = 0; y < n; y++) {
            int moveTo = n - 1;
            for (int x = n - 1; x >= 0; x--) {
                if (board[y][x] != '.') {
                    board[y][moveTo] = board[y][x];
                    if (moveTo != x) { board[y][x] = '.'; }
                    moveTo--;
                }
            }
        }

        // counter
        string erika = string(k, 'R');
        string diabol = string(k, 'B');
        bool erikaScore = false;
        bool diabolScore = false;

        // horizontal
        for (int y = 0; y < n; y++) {
            string lined;
            for (int x = 0; x < n; x++) {
                lined += board[y][x];
            }
             // cout << lined << endl;
            if (lined.find(erika) != string::npos) { erikaScore = true; }
            if (lined.find(diabol) != string::npos) { diabolScore = true; }
        }

        // vertical
        for (int x = 0; x < n; x++) {
            string lined;
            for (int y = 0; y < n; y++) {
                lined += board[y][x];
            }
                  // cout << lined << endl;
            if (lined.find(erika) != string::npos) { erikaScore = true; }
            if (lined.find(diabol) != string::npos) { diabolScore = true; }
        }

        // diagonal topleft to bottomright
        for (int i = -n + 1; i < n; i++) {
            int startY = i < 0 ? abs(i) : 0;
            int startX = i < 0 ? 0 : i;
            string lined;
            for (int j = 0; j < n; j++) {
                if (startX + j >= n || startY + j >= n) break;
                lined += board[startY + j][startX + j];
            }
            // cout << lined << endl;
            if (lined.find(erika) != string::npos) { erikaScore = true; }
            if (lined.find(diabol) != string::npos) { diabolScore = true; }
        }

        // diagonal topright to bottomleft
        for (int i = -n + 1; i < n; i++) {
            int startY= i < 0 ? abs(i) : 0;
            int startX = i < 0 ? n - 1 : i;
            string lined;
            for (int j = 0; j < n; j++) {
                if (startX - j < 0 || startY + j >= n) break;
                lined += board[startY + j][startX - j];
            }
            // cout << lined << endl;
            if (lined.find(erika) != string::npos) { erikaScore = true; }
            if (lined.find(diabol) != string::npos) { diabolScore = true; }
        }

        if (erikaScore && diabolScore) {
            cout << "Dilema" << endl;
        } else if (erikaScore) {
            cout << "Erika" << endl;
        } else if (diabolScore) {
            cout << "Diabol" << endl;
        } else {
            cout << "Nikto" << endl;
        }
    }
    return 0;
}
