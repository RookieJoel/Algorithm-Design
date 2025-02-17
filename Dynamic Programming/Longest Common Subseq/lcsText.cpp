#include<bits/stdc++.h>

using namespace std; 

int main(){ 
    int n,m;
    cin >> n >> m; 
    string x,y;
    cin >> x >> y;
    vector<vector<int>> dp(n+1,vector<int>(n+1));
    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            cin >> dp[i][j];
        }
    }
    int l = dp[n][m];
    string ans="";
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(ans.length() == l) break;
            if(dp[i][j] == dp[i-1][j-1] +1 && x[i-1]==y[j-1]) ans+=x[i-1];
        }
    }

    cout << ans;
}