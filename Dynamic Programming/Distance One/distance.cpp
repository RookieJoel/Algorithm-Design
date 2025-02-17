#include <bits/stdc++.h>
#define MOD 100000007
using namespace std;

int solve(int n, int k) {
    vector<int> dp(n+1),p(n+1);
    dp[0] = 1;
    p[0] =1;
    for(int i =1;i<n+1;i++){
        if(i<=k) dp[i] = 1;
        else{
            dp[i] = p[i-k];
        }
        p[i] = (p[i-1]+dp[i])%MOD;
    }
    return p[n];
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << solve(n, k) << endl;
}
