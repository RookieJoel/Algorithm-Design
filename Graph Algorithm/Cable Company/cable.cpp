#include <bits/stdc++.h>
using namespace std;

int main() {
    int v;
    cin >> v;
    vector<vector<pair<int, int>>> adj(v); 

    for (int i = 0; i < v - 1; i++) {
        for (int j = i + 1; j < v; j++) {
            int x;
            cin >> x;
            adj[i].push_back({j, x});
            adj[j].push_back({i, x}); 
        }
    }

    vector<bool> visited(v, false);
    vector<int> minEdge(v, INT_MAX);
    minEdge[0] = 0;
    set<pair<int, int>> s;
    s.insert({0, 0});

    int total_cost = 0;

    while (!s.empty()) {
        auto [weight, u] = *s.begin();
        s.erase(s.begin());

        if (visited[u]) continue;
        visited[u] = true;
        total_cost += weight;

        for (auto [v2, w] : adj[u]) {
            if (!visited[v2] && w < minEdge[v2]) {
                s.erase({minEdge[v2], v2});
                minEdge[v2] = w;
                s.insert({w, v2});
            }
        }
    }

    cout << total_cost << "\n";
}
