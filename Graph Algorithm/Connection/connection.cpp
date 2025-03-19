#include <bits/stdc++.h>
using namespace std;

int bfs(int node, vector<vector<int>> &adj, int k) {
    queue<pair<int, int>> q;
    vector<bool> visited(adj.size(), false);
    
    q.push({node, 0});
    visited[node] = true;
    
    int count = 0;
    
    while (!q.empty()) {
        auto  u = q.front();
        int x = u.first;
        int depth = u.second;
        q.pop();

        count++; 

        if (depth == k) continue; 

        for (auto &n : adj[x]) {
            if (!visited[n]) {
                visited[n] = true;
                q.push({n, depth + 1});
            }
        }
    }
    return count;
}

int main() {
    int v, e, k;
    cin >> v >> e >> k;
    
    vector<vector<int>> adj(v);
    
    while (e--) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int maxFriends = 0;
    
    for (int i = 0; i < v; i++) {
        maxFriends = max(maxFriends, bfs(i, adj, k));
    }

    cout << maxFriends << endl;
    return 0;
}
