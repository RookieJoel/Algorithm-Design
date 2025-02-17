#include<bits/stdc++.h>

using namespace std; 

vector<int> c;

int solve(int n){
    vector<int> dp(n+1);
    dp[1] = c[1];
    dp[2] = c[2];
    for(int i =3;i<n+1;i++){
        dp[i] = max(c[i],c[i]+dp[i-1]);
    }
    // for(int i =0;i<n+1;i++) cout << dp[i] << " ";
    // cout << endl;
    return dp[n];
}
int main(){
    int n; 
    cin >> n;
    c.resize(n+1);
    for(int i =1;i<=n;i++) cin >> c[i];
    cout << solve(n);
}   