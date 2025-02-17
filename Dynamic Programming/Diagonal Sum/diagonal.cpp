#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> a;

int solve(int n){
    vector<vector<int>> dp(n,vector<int>(n));
    int res = a[0][0];
    for(int i =0;i<n;i++){
        for(int j=0;j<n;j++){
            int temp_i =i,temp_j = j;
            int sum = 0;
            while(temp_i < n && temp_j < n){
                sum+=a[temp_i][temp_j];
                temp_i++;temp_j++;
                res = max(res,sum);
            }
            dp[i][j] = sum;
            
        }
    }

    return res;
}

int main(){
    int n;
    cin >> n;
    a.assign(n,vector<int>(n));
    for(int i =0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> a[i][j];
        }
    }
    cout << solve(n);
}