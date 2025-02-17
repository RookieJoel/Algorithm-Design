#include <bits/stdc++.h>
using namespace std;
vector<int> arr;

int solve(int n){
    vector<vector<int>> dp(n+2,vector<int>(n+2));
    for (int i = 2; i <= n; i++) {
        for (int l = 1, r = i; r <= n; l++, r++) {
            dp[l][r] = max({
                    dp[l+2][r] + max(arr[l], arr[l + 1]),
                    dp[l+1][r-1] + max(arr[l], arr[r]),
                    dp[l][r-2] + max(arr[r], arr[r-1])});
        }
    }

    // for (int i = 0; i <= n; i++) {
    //     for (int l = 0, r = i; r <= n; l++, r++) {
    //         cout << dp[l][r] << " ";
    //     }
    //     cout << endl;
    // }

    return dp[1][n];
}

int main() {
    int n; cin >> n;
    arr.resize(n+1);
    for (int i = 1; i <= n; i++)cin >> arr[i];
    cout << solve(n);
}

