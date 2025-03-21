#include <bits/stdc++.h>

using namespace std; 

int dfs(pair<int,int> p, map<pair<int, int>, vector<pair<int, int>>> &adj, 
         map<pair<int,int>,bool> &visited, pair<int,int> parent, int count) {
    visited[p] = true;
    
    for (auto &x : adj[p]) {
        if (!visited[x]) {
            int cycle_length = dfs(x, adj, visited, p, count + 1);
            if (cycle_length != -1) {
                return cycle_length; // คืนค่าความยาวของวงวน
            }
        } else if (x != parent) { 
            // เจอวงวน -> return ความยาว
            return count + 1;  
        }
    }
    
    return -1; // ไม่เจอวงวน
}

int main() {
    int R, C; 
    cin >> R >> C; 
    map<pair<int, int>, vector<pair<int, int>>> adj;
    vector<vector<int>> grid(R, vector<int>(C));

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> grid[i][j];
            switch (grid[i][j]) {
                case 1:  
                    if (j - 1 >= 0) adj[{i, j}].push_back({i, j - 1});
                    if (j + 1 < C) adj[{i, j}].push_back({i, j + 1});
                    break;
                case 2:  
                    if (i - 1 >= 0) adj[{i, j}].push_back({i - 1, j});
                    if (i + 1 < R) adj[{i, j}].push_back({i + 1, j});
                    break;
                case 3:  
                    if (i - 1 >= 0) adj[{i, j}].push_back({i - 1, j});
                    if (j + 1 < C) adj[{i, j}].push_back({i, j + 1});
                    break;
                case 4:  
                    if (i + 1 < R) adj[{i, j}].push_back({i + 1, j});
                    if (j + 1 < C) adj[{i, j}].push_back({i, j + 1});
                    break;
                case 5:  
                    if (i + 1 < R) adj[{i, j}].push_back({i + 1, j});
                    if (j - 1 >= 0) adj[{i, j}].push_back({i, j - 1});
                    break;
                case 6:  
                    if (i - 1 >= 0) adj[{i, j}].push_back({i - 1, j});
                    if (j - 1 >= 0) adj[{i, j}].push_back({i, j - 1});
                    break;
                default:
                    break;
            }
        }
    }

    int count_cycle = 0;
    int max_cycle = 0;
    map<pair<int,int>,bool> visited;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (!visited[{i, j}]) {
                int cycle_length = dfs({i, j}, adj, visited, {-1, -1}, 0);
                if (cycle_length != -1) {
                    count_cycle++;
                    max_cycle = max(max_cycle, cycle_length);
                }
            }
        }
    }

    cout << count_cycle << " " << max_cycle << "\n";
}
