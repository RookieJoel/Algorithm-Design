#include<bits/stdc++.h>

using namespace std; 

int lcs(string &a, string &b,vector<char> &ans){ 
    vector<vector<int>> dp(a.size()+1,vector<int>(b.size() +1)); 
    for(int i =1;i< a.size()+1;i++){
        for(int j = 1;j< b.size()+1;j++){ 
            if(a[i-1] == b[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
                ans.push_back(a[i-1]);
            }
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }


    return dp[a.size()][b.size()];
}

int main(){
    string n,m; 
    cin >> n >> m;
    vector<char> ans;
    cout << lcs(n,m,ans) << endl ;
    // for(auto &x : ans) cout << x << " ";

}