#include<bits/stdc++.h>
#define ll long long
#define mod 100000007
using namespace std;

int main(){
    ll n;
    cin >> n; 
    vector<ll> dp(n);
    dp[0] = 3;
    dp[1] = 7;
    for(ll i = 2;i<n;i++){
        dp[i] = (2*dp[i-1] + dp[i-2])%mod;
    }
    cout << dp[n-1];
}