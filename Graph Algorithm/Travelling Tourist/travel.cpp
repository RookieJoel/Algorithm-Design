#include<bits/stdc++.h>

using namespace std; 

int main(){
    int n,m,k;
    cin >> n >> m >>k;
    vector<int> s(k+1);
    for(int i=1;i<=k;i++) cin >> s[i];
    vector<vector<int>> cost(n+1,vector<int>(n+1,INT_MAX));
    while(m--){
        int a,b,c;
        cin >> a >> b >> c;
        cost[a][b] = c;
        cost[b][a] = c;
    }

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i == j) cost[i][j] = 0;
    
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(cost[i][j] == 0) continue;
                if(cost[i][k] != INT_MAX && cost[k][j]!=INT_MAX){
                    cost[i][j] = min(cost[i][j],cost[i][k]+cost[k][j]);
                }
            }
        }
    }

    cout << endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout << cost[i][j] << " ";
            }cout << endl;
        }

}
    
