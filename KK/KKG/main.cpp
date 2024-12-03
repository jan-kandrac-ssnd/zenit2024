#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxPathSum = 0;

int m, n;

bool isValid(int x, int y, vector<vector<bool>>& visited) {
    return x >= 0 && x < m && y >= 0 && y < n && !visited[x][y];
}

void findLongestPath(
    const vector<vector<int>>& grid,
    int x,
    int y,
    int currentSum,
    vector<vector<bool>>& visited
) {
    if (!isValid(x, y, visited)) { return; }

    currentSum += grid[x][y];

    if (x == m - 1 && y == 0) {
        maxPathSum = max(maxPathSum, currentSum);
        return;
    }

    visited[x][y] = true;
    findLongestPath(grid, x + 1, y, currentSum, visited);
    findLongestPath(grid, x - 1, y, currentSum, visited);
    findLongestPath(grid, x, y + 1, currentSum, visited);
    findLongestPath(grid, x, y - 1, currentSum, visited);
    visited[x][y] = false;
}

int main() {
    cin >> m >> n;
    long sum = 0;
    vector<vector<int>> grid;
    for (int y = 0; y < m; y++) {
        vector<int> line;
        for (int x = 0; x < n; x++) {
            int input;
            cin >> input;
            line.push_back(input);
            sum += input;
        }
        grid.push_back(line);
    }

    if (m % 2 == 1 || n % 2 == 1) {
        cout << sum << endl;
        return 0;
    }
    vector visited(m, vector(n, false));
    findLongestPath(grid, 0, n - 1, 0, visited);
    cout << maxPathSum << endl;
    return 0;
}