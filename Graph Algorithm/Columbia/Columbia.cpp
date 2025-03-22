#include<bits/stdc++.h>

using namespace std;
int r,c;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int main(){
    cin >> r >>c; 
    vector<vector<int>> fee(r+1,vector<int>(c+1));
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            cin >> fee[i][j];
        }
    }
    vector<vector<int>> visited(r+1,vector<int>(c+1));
    vector<vector<int>> cost(r+1,vector<int>(c+1,INT_MAX));
    set<pair<int,pair<int,int>>> q;
    q.insert({0,{1,1}});
    cost[1][1] = 0;
    while(!q.empty()){
        auto u = q.begin();
        int weight = u->first;
        auto rc = u->second;
        int R = rc.first,C=rc.second;
        q.erase(u);
        if(visited[R][C]) continue;
        visited[R][C] = 1;
        for(int i=0;i<4;i++){
            int nr = R+dx[i];
            int nc = C+dy[i];
            if(nr>=1 && nr <= r && nc >=1 && nc <= c){
                if(cost[nr][nc] > weight+fee[nr][nc]){
                    cost[nr][nc] = weight+fee[nr][nc];
                    q.insert({cost[nr][nc],{nr,nc}});
                }
            }
        }
    }

    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            cout << cost[i][j] << " ";
        }cout << "\n";
    }

}