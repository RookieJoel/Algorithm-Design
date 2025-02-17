#include<bits/stdc++.h>
#define ll long long
using namespace std; 
vector<int> a;

int solve(int n){
    vector<int> b(n);
    b[0] = a[0];
    b[1] = a[0] + a[1];
    b[2] = max(a[0] + a[2] + a[1], a[0] + a[2]);
    for(int i=3;i<n;i++){
        b[i] = max({b[i-1],b[i-2],b[i-3]}) + a[i];
    }   
    // for(int i =0;i<n;i++) cout << b[i] << " ";
    // cout << endl;
    return b[n-1];
}
int main(){
    int n;
    cin >> n ;
    a.resize(n);
    for(int i=0;i<n;i++) cin >> a[i];
    cout << solve(n);
}