#include<bits/stdc++.h>
#define kk 32717
using namespace std;

vector<int> c,a;

int Rn(int n,int k){
    vector<int> mem(n+1);
    for(int i = 0;i<k;i++){
        mem[i] = a[i];
    }
    
    for(int i=k;i<=n+1;i++){
        long long  res = 0;
        for(int j=0;j<k;j++){ // C_i
            long long r = ((c[j]%kk) * (mem[i-j-1]))%kk;
            res+= (r%kk);
        }
        // cout << res << endl;
        mem[i] = res%kk;
    }

    // for(auto &x : mem) cout << x << " ";
    return mem[n];
}

int main(){
    int k,n;
    cin >> k >> n;
    c.resize(k);a.resize(k);
    for(int i=0;i<k;i++) cin >> c[i];
    for(int i=0;i<k;i++) cin >> a[i];
    cout << Rn(n,k);
}