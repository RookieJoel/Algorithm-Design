#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin >> n >> k; 
    vector<int> p(n+1);
    for(int i=1;i<=n;i++) cin >> p[i];
    int x = INT_MAX;
    vector<int> dp(n+1,x);
    dp[1]= p[1];
    dp[0] = 0;
    for(int i=0;i<n;i++){
        if(dp[i] == x) continue;
        for(int j = i+1;j<=min(n,i+k+1);j++){
            int r = min(n,j+k);
            dp[r] = min(dp[r],dp[i]+p[j]);
        }
    } 

    // for(auto &x : dp) cout << x << " ";
    cout << dp[n];
}