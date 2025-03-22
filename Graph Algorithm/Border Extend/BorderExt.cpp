#include <bits/stdc++.h>
using namespace std;

int R, C, K;
vector<vector<int>> grid;
vector<vector<int>> dist;
queue<pair<int, int>> q;

const int dx[4] = {-1, 1, 0, 0}; 
const int dy[4] = {0, 0, -1, 1};

void bfs() {
    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = r + dx[i], nc = c + dy[i];

            if (nr >= 0 && nr < R && nc >= 0 && nc < C) { // Check bounds
                if (grid[nr][nc] == 0 && dist[nr][nc] == -1) { // Unvisited water cell
                    dist[nr][nc] = dist[r][c] + 1; // Update distance
                    if (dist[nr][nc] <= K) {
                        grid[nr][nc] = 2; // Fill the water with land
                        q.push({nr, nc}); // Continue spreading
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

    // Read input grid
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 1) {
                q.push({i, j});  // Push land cells into BFS queue
                dist[i][j] = 0;  // Land cells start at distance 0
            }
        }
    }

    bfs(); // Perform BFS to expand the land

    // Output the modified grid
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << grid[i][j] << " ";
        }
        cout << "\n"; // Use "\n" for faster output
    }
}
