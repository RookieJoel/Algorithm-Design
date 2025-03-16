#include<bits/stdc++.h>
#define kk 32717
using namespace std;

vector<int> c,a;

int Rn(int n,int k){
    vector<int> dp(n+1);
    for(int i = 0;i<k;i++){
        dp[i] = a[i];
    }
    
    for(int i=k;i<=n+1;i++){
        long long  res = 0;
        for(int j=0;j<k;j++){ // C_i
            long long r = ((c[j]%kk) * (dp[i-j-1]))%kk;
            res+= (r%kk);
        }
        // cout << res << endl;
        dp[i] = res%kk;
    }

    // for(auto &x : mem) cout << x << " ";
    return dp[n];
}

int main(){
    int k,n;
    cin >> k >> n;
    c.resize(k);a.resize(k);
    for(int i=0;i<k;i++) cin >> c[i];
    for(int i=0;i<k;i++) cin >> a[i];
    cout << Rn(n,k);
}