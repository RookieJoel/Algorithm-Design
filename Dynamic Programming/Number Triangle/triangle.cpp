#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> a[i][j];
        }
    }
    if (n == 1) {
        cout << a[0][0] << endl;
        return 0;
    }

    vector<vector<int>> dp(n, vector<int>(n));
    dp[0][0] = a[0][0];
    int res = a[0][0];
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0) {
                dp[i][j] = dp[i-1][j] + a[i][j];
            } else if (j == i) {
                dp[i][j] = dp[i-1][j-1] + a[i][j];
            } else {
                dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + a[i][j];
            }
            res = max(res,dp[i][j]);
        }
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j <= i; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout <<endl;
    // }
    cout << res << endl;
}
