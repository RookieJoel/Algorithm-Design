#include <bits/stdc++.h>
using namespace std;

const int INF = -1e9;
int dp[1 << 20][20];

int main() {
    int n;
    cin >> n;
    vector<vector<int>> w(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> w[i][j];

    //  init all cost of i->j to be INF
    for (int i = 0; i < (1 << n); i++)
        for (int j = 0; j < n; j++)
            dp[i][j] = INF;

    dp[1 << 0][0] = 0; //start from city 0

    for (int mask = 0; mask < (1 << n); mask++) {
        for (int u = 0; u < n; u++) {
            if (!(mask & (1 << u))) continue;
            for (int v = 0; v < n; v++) {
                if (mask & (1 << v)) continue;
                int next = mask | (1 << v);
                dp[next][v] = max(dp[next][v], dp[mask][u] + w[u][v]);
            }
        }
    }

    cout << dp[(1 << n) - 1][n - 1] << "\n";
    return 0;
}
