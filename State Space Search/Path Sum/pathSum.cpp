#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1}; 
int main(){
    int R,C,k;
    cin>>R>>C>>k;
    vector<vector<int>> grid(R+1,vector<int>(C+1)),dist(R+1,vector<int>(C+1,INT_MAX));
    queue<pii> q;
    for(int i=1;i<=R;i++){
        for(int j=1;j<=C;j++){
        cin>>grid[i][j];
        if(grid[i][j] == 1){
            q.push({i,j});dist[i][j] = 0;
        }
        }
    }
    while(!q.empty()){
        auto &x = q.front();q.pop();
        int r = x.first;
        int c = x.second;
        if(dist[r][c] >=k)continue;;
        for(int i=0;i<4;i++){
            int nr = r+dx[i];
            int nc = c+dy[i];
            if(nr>=1 && nr <=R && nc >=1 && nc <= C && dist[nr][nc] == INT_MAX && grid[nr][nc] == 0){
                dist[nr][nc] = dist[r][c]+1;
                grid[nr][nc] = 2;
                q.push({nr,nc});
            }
        }
    }
    for(int i=1;i<=R;i++){
        for(int j=1;j<=C;j++){
            cout << grid[i][j] << " ";
        }cout << "\n";
    }

}