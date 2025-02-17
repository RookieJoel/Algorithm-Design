#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    long long n,q;
    cin >> n >> q;
    vector<pair<ll,ll>> a(n);
    for(int i = 0;i<n;i++){
        ll x,y;
        cin >> x >> y;
        a[i] = {x,y};
    }
    sort(a.begin(),a.end());
    vector<ll> b(n);
    b[0] = a[0].second;
    for(int i = 1;i<n;i++){
        b[i] = b[i-1] + a[i].second;
    }
    while(q--){
        ll x;
        cin >> x;
        int index = lower_bound(b.begin(),b.end(),x) - b.begin();
        cout << a[index].first << endl;
    }

}