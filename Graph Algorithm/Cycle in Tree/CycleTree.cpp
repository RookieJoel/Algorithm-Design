#include <bits/stdc++.h>

using namespace std;

vector<int> parent;
vector<int> visited;
int cycle_start = -1, cycle_end = -1;

bool cycleDetection(vector<vector<int>> &adj, int node, int par) {
    visited[node] = 1;

    for (int neighbor : adj[node]) {
        if (neighbor == par) continue; 
        
        if (visited[neighbor] == 0) {
            parent[neighbor] = node;
            if (cycleDetection(adj, neighbor, node)) return true;
        } else { // พบ Cycle
            cycle_start = neighbor;
            cycle_end = node;
            return true;
        }
    }

    return false;
}

int findCycleSize(int start) {
    int count = 1;
    int current = cycle_end;

    while (current != start) {
        count++;
        current = parent[current];
    }

    return count + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    
    vector<vector<int>> adj(n);
    parent.assign(n, -1);
    visited.assign(n, 0);

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for (int i = 0; i < n; i++) {
        if (visited[i] == 0 && cycleDetection(adj, i, -1)) {
            break;
        }
    }

    cout << findCycleSize(cycle_start) - 1 ;
}
