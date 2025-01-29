// #include<iostream>
// #include<cstdio>
// #include<cstring>
// #define ll long long
// using namespace std;
// ll n,f[18];
// int cal(ll x){ 
//     int res,i=16;
//     if(x<=11)return min(x,13-x);
//     while(f[i-1]>=x)i--;
//     res=((x/f[i-1])*(i-1))+cal(x%f[i-1]);
//     if(x<f[i]-x)return res;
//     return min(res,i+cal(f[i]-x));
// }
// int main()
// {
//     f[1]=1;
//     for(int i=2;i<=16;i++)f[i]=10*f[i-1]+1;
//     scanf("%I64d",&n);
//     printf("%d",cal(n));
//     return 0;
// }

#include<bits/stdc++.h>
#define ll long long
using namespace std; 
vector<ll> ones = {1,11,111,1111,11111,111111,1111111,11111111,111111111} ;

int q(ll n){
    for(int i=ones.size()-1;i>=0;i--){
        if(ones[i] <= abs(n)) return i;
    }
}

int solve(ll n){
    if(n<=11) return (n<=6) ? n : (13-n);
    int qk = ones[q(n)];
    int i = to_string(ones[q(n)]).size();
    int res = floor(abs(n)/qk)*i + solve(n%qk);
    int res2 = 1+floor(abs(n)/qk)*i + solve(n%qk);
    if(n < ones[q(n)-1]) return res;
    return min(res,res2);
}
int main(){
    ll n;
    cin >> n; 
    cout << solve(n);
}