#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
vector<int> graph[MAXN], rev_graph[MAXN], order;
vector<bool> visited;
vector<vector<int>> sccs;

void dfs1(int u) {
    visited[u] = true;
    for (int v : graph[u]) {
        if (!visited[v])
            dfs1(v);
    }
    order.push_back(u);
}

void dfs2(int u, vector<int>& scc) {
    visited[u] = true;
    scc.push_back(u);
    for (int v : rev_graph[u]) {
        if (!visited[v])
            dfs2(v, scc);
    }
}

int main() {
    int n;
    cin >> n;
    for(int u = 0; u < n; u++) {
        int m;
        cin >> m;
        for(int j = 0; j < m; j++) {
            int v;
            cin >> v;
            graph[u].push_back(v);
            rev_graph[v].push_back(u); // reverse edge
        }
    }

    visited.assign(n, false);
    for(int i = 0; i < n; i++)
        if (!visited[i]) dfs1(i);

    reverse(order.begin(), order.end());

    visited.assign(n, false);
    for(int u : order) {
        if (!visited[u]) {
            vector<int> scc;
            dfs2(u, scc);
            sccs.push_back(scc);
        }
    }

    vector<int> sizes;
    for (auto& scc : sccs)
        sizes.push_back(scc.size());

    sort(sizes.begin(), sizes.end());
    for (int sz : sizes)
        cout << sz << " ";
    cout << endl;
}
