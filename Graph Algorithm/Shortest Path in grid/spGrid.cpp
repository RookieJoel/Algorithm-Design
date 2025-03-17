#include <bits/stdc++.h>

using namespace std;

vector<int> dx = {-1, 1, 0, 0}; // U,D
vector<int> dy = {0, 0, -1, 1}; // L,R

int bfs(int r, int c, vector<vector<char>> &grid) {
    vector<vector<int>> dist(r, vector<int>(c, -1)); //init distance
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    dist[0][0] = 0; 
    while (!q.empty()) {
        auto current = q.front();
        q.pop();
        int x = current.first, y = current.second; 
        
        // met the target
        if (x == r - 1 && y == c - 1) {
            return dist[x][y];
        }

        // moving to 4 directions
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < r && ny < c && grid[nx][ny] == '.' && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push(make_pair(nx, ny));
            }
        }
    }

    return -1; 
}

int main() {
    int r, c;
    cin >> r >> c;
    vector<vector<char>> grid(r, vector<char>(c));

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> grid[i][j];
        }
    }
    if(bfs(r, c, grid) == -1) cout << -1 << endl;
    else cout << bfs(r, c, grid) << endl;
}
