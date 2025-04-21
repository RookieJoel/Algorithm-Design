#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
int n,m,k;
vector<int> a;
int best = INT_MAX;
void solve(int idx,int count,int curSum){
    if(count == m){
        best = min(best,abs(k-curSum));
        return;
    }
    if(idx == n)return;
    if (count + (n - idx) < m) return;
    if(curSum > k && abs(curSum-k) > best) return;
    //take
    solve(idx+1,count+1,curSum+a[idx]);
    //dont
    solve(idx+1,count,curSum);
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin>>n>>m>>k;
    a.resize(n);
    for(int i=0;i<n;i++)cin>>a[i];
    solve(0,0,0);
    cout << best;
}