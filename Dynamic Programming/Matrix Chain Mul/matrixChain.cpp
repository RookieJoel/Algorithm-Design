#include <bits/stdc++.h>

using namespace std;
vector<int> a;
vector<vector<int>> dp;

int solve(int l, int r) {
    if (l == r) return 0;  // Base case: No cost for a single matrix
    if (dp[l][r] != -1) return dp[l][r];

    int minCost = INT_MAX;
    for (int i = l; i < r; i++) {
        int cost = solve(l, i) + solve(i + 1, r) + (a[l] * a[i + 1] * a[r + 1]);
        minCost = min(minCost, cost);
    }

    return dp[l][r] = minCost;
}

int main() {
    int n;
    cin >> n;
    
    // Correctly resize 'a' to store n+1 elements
    a.resize(n + 1);
    for (int i = 0; i <= n; i++) cin >> a[i];

    // Resize dp properly
    dp.assign(n, vector<int>(n, -1));

    // Call solve(0, n-1) since we have n matrices (0-based indexing)
    cout << solve(0, n - 1) << endl;

    return 0;
}
