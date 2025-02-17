#include<bits/stdc++.h>

using namespace std;

int main(){
    int r,c;
    cin >> r >> c; 
    vector<vector<int>> grid(r+1,vector<int>(c+1));
    for(int i = 1; i <= r; i++){
        string s;
        cin >> s;
        for(int j = 1; j <= c; j++){
            grid[i][j] = s[j - 1] - '0';
        }
    }
    

    // for(int i=0;i<r+1;i++){
    //     for(int j=0;j<c+1;j++){
    //         cout << grid[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    int ans = grid[0][0];
    vector<vector<int>> dp(r+1,vector<int>(c+1));
    for(int i=r;i>=0;i--){
        for(int j=c;j>=0;j--){
            if(grid[i][j] == 0) continue;
            if(j == c || i == r) dp[i][j] = grid[i][j];
            else if(grid[i][j] == 1 && grid[i][j+1] == 1
                    && grid[i+1][j+1] == 1 && grid[i+1][j] == 1){
                        dp[i][j] = grid[i][j] + min({dp[i][j+1],dp[i+1][j+1],dp[i+1][j]});
            }else{ 
                dp[i][j] = 1;
            }
            ans = max(ans,dp[i][j]);
        }
    }

    cout << ans;

}