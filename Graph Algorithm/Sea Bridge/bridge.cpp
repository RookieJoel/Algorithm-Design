#include <bits/stdc++.h>
using namespace std;

vector<int> dx = {-1, 1, 0, 0}; // U,D
vector<int> dy = {0, 0, -1, 1}; // L,R

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int R, C;
    cin >> R >> C;

    vector<vector<int>> grid(R, vector<int>(C));
    vector<vector<int>> dist(R, vector<int>(C, -1));
    queue<pair<int, int>> q;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 1) {
                q.push({i, j});
                dist[i][j] = 1; // เริ่มต้นที่ระยะ 1
            }
        }
    }

    while (!q.empty()) {
        auto u = q.front(); q.pop();
        int r = u.first;
        int c = u.second;

        for (int d = 0; d < 4; d++) {
            int nr = r + dx[d];
            int nc = c + dy[d];

            if (nr >= 0 && nr < R && nc >= 0 && nc < C) {
                if (dist[nr][nc] == -1 && grid[nr][nc] != 3) {
                    dist[nr][nc] = dist[r][c] + 1;
                    if (grid[nr][nc] == 2) {
                        cout << dist[nr][nc] << "\n";
                        return 0;
                    }
                    q.push({nr, nc});
                }
            }
        }
    }

}
