#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
ll n,f[18];
int cal(ll x){ 
    int res,i=16;
    if(x<=11)return min(x,13-x);
    while(f[i-1]>=x)i--;
    res=((x/f[i-1])*(i-1))+cal(x%f[i-1]);
    if(x<f[i]-x)return res;
    return min(res,i+cal(f[i]-x));
}
int main()
{
    f[1]=1;
    for(int i=2;i<=16;i++)f[i]=10*f[i-1]+1;
    scanf("%I64d",&n);
    printf("%d",cal(n));
    return 0;
}
