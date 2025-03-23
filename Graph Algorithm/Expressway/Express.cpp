#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,c;
    cin >> n >> c;
    vector<vector<int>> cost(n+1,vector<int>(n+1,INT_MAX));
    cost[1][2] = c;
    cost[2][1] = c;

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) 
            if(i ==j) cost[i][j] = 0;

    for(int i=3;i<=n;i++){
        int k;
        cin >> k;
        while(k--){
            int t,p;
            cin >> t >> p;
            cost[i][t] = p;
            cost[t][i] = p;
        }
    }
    vector<int> ans(n+1);
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(cost[i][j] == 0) continue;
                if(cost[i][k] != INT_MAX && cost[k][j] != INT_MAX){
                    cost[i][j] = min(cost[i][j],cost[i][k]+cost[k][j]);
                }
            }
        }
        ans[k] = cost[1][2];
    }

    for(int i=3;i<=n;i++) cout << ans[i] << " ";

}