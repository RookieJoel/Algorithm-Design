#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> Ki(8);
vector<vector<pair<int, int>>> adj;
vector<bool> found(8, false);

void dfs(int node, int sum, int target_index, vector<bool> &visited) {
    if (sum == Ki[target_index]) {
        found[target_index] = true;
        return;
    }
    if (sum > Ki[target_index]) return;

    visited[node] = true;
    for (auto [next, w] : adj[node]) {
        if (!visited[next] && !found[target_index]) {
            dfs(next, sum + w, target_index, visited);
        }
    }
    visited[node] = false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < 8; ++i) cin >> Ki[i];

    adj.resize(n);
    for (int i = 0; i < m; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].emplace_back(b, w);
        adj[b].emplace_back(a, w); // กราฟไม่มีทิศ
    }

    for (int k = 0; k < 8; ++k) {
        found[k] = false;
        for (int start = 0; start < n && !found[k]; ++start) {
            vector<bool> visited(n, false);
            dfs(start, 0, k, visited);
        }
    }

    for (int i = 0; i < 8; ++i) {
        cout << (found[i] ? "YES" : "NO") << '\n';
    }

    return 0;
}
