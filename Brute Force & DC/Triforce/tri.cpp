#include <bits/stdc++.h>
using namespace std;

// Function to check if a 2x2 matrix is a Triforce and return its type
int checkBaseCase(const vector<vector<int>>& grid, int r, int c) {
    // Bottom-right cell must be 0
    if (grid[r + 1][c + 1] != 0) return 0;

    // Collect non-zero values in the other three cells
    vector<int> values;
    for (int i = r; i < r + 2; i++) {
        for (int j = c; j < c + 2; j++) {
            if (i == r + 1 && j == c + 1) continue; // Skip bottom-right
            if (grid[i][j] == 0) return 0; // Non-zero condition
            values.push_back(grid[i][j]);
        }
    }

    // Check for at least two matching values
    map<int, int> freq;
    for (int val : values) freq[val]++;
    for (auto it = freq.begin(); it != freq.end(); ++it) { // Explicit iterator
        if (it->second >= 2) return it->first; // Return the type of Triforce
    }

    return 0; // Not a Triforce
}

// Recursive function to check if a matrix is a Triforce and return its type
int solve(const vector<vector<int>>& grid, int r, int c, int n) {
    // Base case: check 2x2 matrix
    if (n == 2) return checkBaseCase(grid, r, c);

    // Divide the grid into four quadrants
    int m = n / 2; // Midpoint
    int P = solve(grid, r, c, m);          // Top-left quadrant
    int Q = solve(grid, r, c + m, m);      // Top-right quadrant
    int R = solve(grid, r + m, c, m);      // Bottom-left quadrant
    int S = solve(grid, r + m, c + m, m);  // Bottom-right quadrant

    // Ensure S is entirely 0
    for (int i = r + m; i < r + n; i++) {
        for (int j = c + m; j < c + n; j++) {
            if (grid[i][j] != 0) return 0; // If any value in S is non-zero
        }
    }

    if(P == 0 || Q == 0 || R == 0) return 0;
    // Count the types of P, Q, R
    map<int, int> typeCount;
    if (P != 0) typeCount[P]++;
    if (Q != 0) typeCount[Q]++;
    if (R != 0) typeCount[R]++;

    // Check if at least two quadrants share the same type
    for (auto it = typeCount.begin(); it != typeCount.end(); ++it) { // Explicit iterator
        if (it->second >= 2) return it->first;
    }

    return 0; // Not a Triforce
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Read input for three tests
    for (int t = 0; t < 3; t++) {
        int n;
        cin >> n;

        vector<vector<int>> grid(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        // Solve for this grid and output the result
        cout << solve(grid, 0, 0, n) << "\n";
    }

    return 0;
}
