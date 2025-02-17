#include<bits/stdc++.h>
using namespace std; 

int main(){
    int n,idx=2;
    cin >> n;
    int k = 2e9;
    vector<long long> psum(3);
    psum[0]=0;
    psum[1]=1;
    psum[2]=3;
    while(psum[psum.size()-1] <= k){
        if(psum.size() > psum[idx]){
            idx++;
        }
        psum.push_back(psum[psum.size()-1]+idx);
    }

    // for(auto &x: psum) cout << x << " ";
    while(n--){
        long long i;
        cin >> i;
        long long ans = lower_bound(psum.begin(),psum.end(),i) - psum.begin();
        cout << ans << endl;
    }
    
}