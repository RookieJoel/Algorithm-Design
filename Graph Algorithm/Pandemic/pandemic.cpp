#include<bits/stdc++.h>

using namespace std; 

vector<int> dx = {-1,1,0,0};
vector<int> dy = {0,0,-1,1};

int R,C,T;
vector<vector<int>> dist;
void bfs( queue<pair<int,int>> q,vector<vector<int>> &grid){
    while(!q.empty()){
        auto u = q.front();
        int r = u.first;
        int c = u.second;
        q.pop();
        for(int i =0;i<4;i++){
            int nr = r + dx[i];
            int nc = c + dy[i];
            if(nr >= 0 && nr < R && nc >=0 && nc < C){
                if(dist[nr][nc]== -1 && grid[nr][nc] != 2){
                    dist[nr][nc] = dist[r][c] + 1;
                    if(dist[nr][nc] <= T){
                        grid[nr][nc] = 1;
                        q.push({nr,nc}); 
                    }
                }
            }
        }
    }
}

int main(){
    cin >> R >> C >> T;
    vector<vector<int>> grid(R,vector<int>(C));
    dist.assign(R, vector<int>(C,-1));
    queue<pair<int,int>> q;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin >> grid[i][j];
            if(grid[i][j] == 1){
                q.push({i,j});
                dist[i][j] = 0;
            }
        }
    }

    bfs(q,grid);

    int count = 0;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(grid[i][j] == 1){
                count++;
            }
        }
    }
    cout << count ;
}