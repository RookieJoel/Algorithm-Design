#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,m;
    cin >> n>>m;
    vector<vector<int>> a(n+1,vector<int>(m+1));
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            cin >> a[i][j];
        }
    }
    vector<vector<int>> dp(n+1,vector<int>(m+1));
    dp[1][1] = a[1][1];
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(i == 1 ) dp[i][j] = dp[i][j-1]+a[i][j];
            else if(j == 1) dp[i][j] = dp[i-1][j]+a[i][j];
            else dp[i][j] = max((max(dp[i][j-1],dp[i-1][j])+a[i][j]),dp[i-1][j-1]+2*a[i][j]);
        }
    }
    // cout <<endl;
    // for(int i=0;i<n+1;i++){
    //     for(int j=0;j<m+1;j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout <<endl;
    // }

    cout << dp[n][m];
}