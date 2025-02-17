#include<bits/stdc++.h>
#define mod 1997
using namespace std;

int main(){
    int n,k;
    cin >> n>> k; 
    vector<int> a(n+1);
    vector<vector<int>> dp(n+1,vector<int>(k+1));
    for(int i=1;i<=n;i++){
        for(int j=1; j<=min(i,k); j++){
            if(j==1) dp[i][j] = 1;
            else if(i == j) dp[i][j] = 1;
        }
    }

    for(int i=2;i<=n;i++){
        for(int j=2; j<=min(i,k); j++){
            long long t1 = (j * dp[i-1][j]) % mod;
            long long t2 = dp[i-1][j-1]; 
            dp[i][j] = (t1 + t2) % mod;
        }
    }


    cout << dp[n][k];
}