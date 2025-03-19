#include <bits/stdc++.h>
using namespace std;

vector<int> beauty; 
int sum;

void spread_fire(int node, vector<vector<int>> &adj) {
    queue<int> q;
    q.push(node);

    if (beauty[node] == 0) return;

    sum -= beauty[node];
    beauty[node] = 0; 

    while (!q.empty()) { 
        int u = q.front();
        q.pop();
        for (auto &n : adj[u]) {
            if (beauty[n] > 0) { 
                sum -= beauty[n];
                beauty[n] = 0;
                q.push(n);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    beauty.resize(n);
    vector<vector<int>> adj(n);
    sum = 0;

    for (int i = 0; i < n; i++) {
        cin >> beauty[i];
        sum += beauty[i];
    }

    vector<int> fire(k);
    for (int i = 0; i < k; i++) cin >> fire[i];

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    for (auto &d : fire) {
        spread_fire(d, adj);
        cout << sum << " ";
    }
}
