#include <bits/stdc++.h>
using namespace std;

bool bfs(int node, vector<vector<int>> &adj, vector<int> &visited) {
    queue<int> q;
    q.push(node);
    visited[node] = 1;
    
    int node_count = 0;
    int edge_count = 0;
    int leaf_count = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        node_count++;
        edge_count += adj[u].size(); // Count all edges in this component

        if (adj[u].size() == 1) {
            leaf_count++; // Counting leaf nodes 
        }
        for (auto &v : adj[u]) {
            if (!visited[v]) {
                visited[v] = 1;
                q.push(v);
            }
        }
    }

    edge_count /= 2;

    return (edge_count == node_count - 1) && (leaf_count == 2 || node_count == 1);
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    int v, e;
    cin >> v >> e;
    vector<vector<int>> adj(v);

    while (e--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int ans = 0;
    vector<int> visited(v, 0);

    for (int i = 0; i < v; i++) {
        if (adj[i].empty()) {
            ans++;
            visited[i] = 1;
        }
    }

    for (int i = 0; i < v; i++) {
        if (!visited[i]) {
            if (bfs(i, adj, visited)) {
                ans++;
            }
        }
    }

    cout << ans << "\n";
}
