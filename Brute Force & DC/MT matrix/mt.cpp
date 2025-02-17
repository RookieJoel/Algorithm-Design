#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll solve(ll n,ll r, ll c,ll u,ll v,ll w,ll p){
    if(n==1){
        if(r==1 && c == 1) return u;
        if (r == 1 && c == 2) return v;
        if (r == 2 && c == 1) return w;
        if (r == 2 && c == 2) return p;
    }
    ll mid = 1LL << (n-1);
    //Q1
    if(r <= mid && c <= mid){
        return solve(n-1,r,c,u,v,w,p);
    }
    //Q2
    else if(r <= mid && mid < c){
        return solve(n-1,c-mid,r,u,v,w,p);
    }
    //Q3
    else if(r > mid && c <= mid){
        return -solve(n-1,r-mid,c,u,v,w,p);
    }
    else return -solve(n-1,c-mid,r-mid,u,v,w,p);

}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    ll n,m;
    cin >> n >> m;
    ll u,v,w,p;
    cin >> u >> v >> w >> p;
    while(m--){
        ll r,c;
        cin >> r >> c;
        cout << solve(n,r,c,u,v,w,p) << "\n";
    }
}