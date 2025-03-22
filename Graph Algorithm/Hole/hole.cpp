#include <bits/stdc++.h>
using namespace std;

const int MAX = 1001;
int grid[MAX][MAX];        // -1 = hole, 0 = normal
int dist[MAX][MAX];        
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

int main(){
    int n, a, b;
    cin >> n >> a >> b;

    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        grid[x][y] = -1;
    }

    for(int i = 0; i < MAX; i++)
        for(int j = 0; j < MAX; j++)
            dist[i][j] = INT_MAX;

    queue<pair<int,int>> q;
    q.push({a, b});
    dist[a][b] = 0;

    while(!q.empty()){
        auto [r, c] = q.front(); q.pop();

        for(int i = 0; i < 4; i++){
            int nr = r + dx[i];
            int nc = c + dy[i];
            if(nr >= 1 && nr <= 1000 && nc >= 1 && nc <= 1000){
                int cost = dist[r][c] + (grid[nr][nc] == -1 ? 1 : 0);
                if(cost < dist[nr][nc]){
                    dist[nr][nc] = cost;
                    q.push({nr, nc});
                }
            }
        }
    }

    int answer = INT_MAX;
    for(int i = 1; i <= 1000; i++){
        answer = min({answer, dist[1][i], dist[1000][i], dist[i][1], dist[i][1000]});
    }

    cout << answer << endl;
}
