#include<bits/stdc++.h>

using namespace std;

void solve(vector<int> &a,int target){
    for(int i =0;i<a.size();i++){
        int l = i+1;
        int r = a.size()-1;
        while(l <r){
            if(a[i] + a[r]+a[l] == target) {
                cout << "YES" << endl;
                return;
            }
            else a[i] + a[r]+a[l] < target ? l++ : r--;
        }
    }
    cout << "NO" << endl;
}

int main(){
    int n,m; 
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i =0;i<m;i++){
        int x;
        cin >> x;
        solve(a,x);
    }
}