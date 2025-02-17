#include <bits/stdc++.h>
#define mod 1000003;
using namespace std;

int main(){


    int n, k;
    cin >> n >> k; 
    vector<int> S(k);
    for(int i=0; i<k; i++){
        cin >> S[i];
    }

    vector<int> dp(n+1);
    dp[0] = 1; 
    for(int i=1; i<=n; i++){
        for(int x : S){
            if(i - x >= 0){
                dp[i] = (dp[i] + dp[i - x]) % mod;
            }
        }
    }

    cout << dp[n] % mod;
}
