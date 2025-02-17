#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> v(n+1);
    vector<int> w(n+1);
    for(int i=1;i<n+1;i++) cin >> v[i];
    for(int i=1;i<n+1;i++) cin >> w[i];
    vector<vector<int>> a(n+1,vector<int>(m+1));
    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            cin >> a[i][j];
        }
    }
    vector<int> ans;
    int j = m;
    for(int i=n;i>0;i--){
        if(a[i][j] == 0) break;
         if(a[i][j] == a[i-1][j-w[i]]+v[i]){
                ans.push_back(i);
                j-=w[i];
        }
    }
    cout << ans.size() << endl;
    for(auto &x : ans) cout << x << " ";


}