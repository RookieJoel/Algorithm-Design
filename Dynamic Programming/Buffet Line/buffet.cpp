#include<bits/stdc++.h>

using namespace std;
int n,m,k;
vector<int> d; //delicious
vector<int> prefix;
 
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin >> n >> k >> m;
    d.resize(n+1);
    prefix.resize(n+1);
    for(int i=1;i<=n;i++){
        cin >> d[i];
        prefix[i] = prefix[i-1] + d[i]-m;
    }
    while(k--){
        int a,b;
        cin >> a >> b;
        int idx = lower_bound(prefix.begin(),prefix.end(),prefix[a-1]+b) - prefix.begin();
        cout << idx << "\n";
    }
}