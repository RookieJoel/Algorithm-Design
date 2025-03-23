#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
    while(m--){
        int a,b,w;
        cin >> a >> b >> w; 
        dist[a][b] = w;
        dist[b][a] = w;
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(i == j) dist[i][j] = 0;
        
    
    int ans = INT_MIN;
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dist[i][j] == 0)continue;
                if(dist[i][k] != INT_MAX && dist[k][j] != INT_MAX){
                    dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ans = max(ans,dist[i][j]);
        }
    }
    cout << ans;

}