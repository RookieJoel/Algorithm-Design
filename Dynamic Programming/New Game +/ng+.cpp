#include <bits/stdc++.h>
#define MOD 100000007
using namespace std;

int R, C;
int grid[505][505]; 
//  0 = X, 1 = Y, 2 = Z, 3 = none
int dp[505][505][5];

int solve(int row, int col, int last) {
    if(col == C) return 1;
    if(dp[row][col][last] != -1) return dp[row][col][last];
    
    long long ways = 0;
    
    if(last != 0 && row - 1 >= 1 && grid[row - 1][col+1] == 0) {
        ways = (ways + solve(row - 1, col+1, 0)) % MOD;
    }
    
    if(last != 1 && grid[row][col+1] == 0) {
        ways = (ways + solve(row, col+1, 1)) % MOD;
    }
    
    if(last != 2 && row + 1 <= R && grid[row + 1][col+1] == 0) {
        ways = (ways + solve(row + 1, col+1, 2)) % MOD;
    }
    
    return dp[row][col][last] = ways;
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> R >> C;
    for(int i = 1; i <= R; i++){
        for(int j = 1; j <= C; j++){
            cin >> grid[i][j];
        }
    }
    
    memset(dp, -1, sizeof(dp));
    
    long long ans = 0;
    for (int i = 1; i <= R; i++){
        if(grid[i][1] == 0){
            ans = (ans + solve(i, 1, 3)) % MOD;
        }
    }
    
    cout << ans << "\n";
}
