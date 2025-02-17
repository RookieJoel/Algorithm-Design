#include<bits/stdc++.h>
#define mod 100000007
using namespace std;


// Brute force approach
// bool check(string &cur){
//     int sz = cur.size();
//     if(sz < 3) return false;
//     return cur[sz-3] == '1' && cur[sz-2] == '0' && cur[sz-1] == '1';
// }

// void gen(int n,string &cur,int &ans){
//     if(cur.size() == n){
//             ans = (ans+1)%mod;
//             return;
//     }

//     cur.push_back('0');
//     if(!check(cur)) gen(n,cur,ans);
//     cur.pop_back();

//     cur.push_back('1');
//     if(!check(cur)) gen(n,cur,ans);
//     cur.pop_back();
// }

long long solve(int n){
    vector<long long> dp(n+1);
    dp[0] = 1;
    dp[1] = 2;
    dp[2] = 4;
    dp[3] = 7;
    for(int i =4;i<n+1;i++){
        dp[i] = (dp[i-1]%mod + dp[i-2]%mod + dp[i-4]%mod)%mod;
    }

    for(auto &x : dp) cout << x << " ";
    cout << endl;

    return dp[n];
}

int main(){
    int n,ans = 0;
    cin >>n; 
    cout << solve(n);
}