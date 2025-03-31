#include <bits/stdc++.h>
using namespace std;

int R, C, K;
vector<vector<int>> grid;
vector<vector<int>> dist;
queue<pair<int, int>> q;

int dx[4] = {-1, 1, 0, 0}; 
int dy[4] = {0, 0, -1, 1};

void bfs() {
    while (!q.empty()) {
        auto u = q.front();
        int r = u.first;
        int c = u.second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = r + dx[i], nc = c + dy[i];

            if (nr >= 0 && nr < R && nc >= 0 && nc < C) {
                if (grid[nr][nc] == 0 && dist[nr][nc] == -1) { 
                    dist[nr][nc] = dist[r][c] + 1; 
                    if (dist[nr][nc] <= K) {
                        grid[nr][nc] = 2; 
                        q.push({nr, nc}); 
                    }
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> R >> C >> K;
    grid.resize(R, vector<int>(C));
    dist.assign(R, vector<int>(C, -1));

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 1) {
                q.push({i, j});  
                dist[i][j] = 0;  
            }
        }
    }

    bfs(); 

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
}
