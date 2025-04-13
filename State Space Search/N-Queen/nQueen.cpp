#include <bits/stdc++.h>
using namespace std;

bool check(vector<vector<int>> &grid, int row, int col, int n) {
    // col check
    for (int i = 0; i < row; i++) {
        if (grid[i][col] == 1) return false;
    }
    // diagonal
    for (int i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--) {
        if (grid[i][j] == 1) return false;
    }
    // diagonal upper right
    for (int i = row-1, j = col+1; i >= 0 && j < n; i--, j++) {
        if (grid[i][j] == 1) return false;
    }
    return true;
}

void solve(vector<vector<int>> &grid, int row, int n, int &ans) {
    if (row == n) {
        ans++;
        return;
    }
    for (int col = 0; col < n; col++) {
        if (check(grid, row, col, n)) {
            grid[row][col] = 1;          
            solve(grid, row + 1, n, ans); 
            grid[row][col] = 0;          
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n, 0)); // Q = 1
    int ans = 0;
    solve(grid, 0, n, ans);
    cout << ans << endl;
}
