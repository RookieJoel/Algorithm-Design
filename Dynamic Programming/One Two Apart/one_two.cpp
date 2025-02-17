#include<bits/stdc++.h>
#define mod 100000007

using namespace std;

int solve(int n){
    vector<int> dp(n+1);
    dp[0] = 0;dp[1] = 3;dp[2] = 7;dp[3] = 15;
    for(int i =4;i<n+1;i++){
        dp[i] = (dp[i-1]*2 + dp[i-3]) % mod;
    }

    return dp[n];
}

vector<int> a;
int main(){
    int n;
    cin >> n; 
    cout << solve(n);
}