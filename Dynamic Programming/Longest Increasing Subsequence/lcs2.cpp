#include<bits/stdc++.h>

using namespace std; 

int lcs(vector<int> &a, vector<int> &b){ 
    vector<vector<int>> dp(b.size()+1,vector<int>(a.size() +1)); 
    for(int i =1;i< a.size()+1;i++){
        for(int j = 1;j< b.size()+1;j++){ 
            if(a[i-1] == b[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }

    // for(int i =0;i< a.size()+1;i++){
    //     for(int j = 0;j< b.size()+1;j++){ 
    //         cout << dp[i][j] << " ";
    //     }
    //     cout <<endl; 
    // }


    return dp[a.size()][b.size()];
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    vector<int> b(a.begin(),a.end());
    sort(b.begin(),b.end());
    cout << lcs(a,b) << endl ;
}