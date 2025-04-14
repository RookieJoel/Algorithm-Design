#include <bits/stdc++.h>
using namespace std;

int n, e;
vector<vector<int>> adj;
vector<int> color;

bool isValid(int node, int c) {
    for (int neighbor : adj[node]) {
        if (color[neighbor] == c) return false;
    }
    return true;
}

bool assignColor(int node, int maxColor) {
    if (node == n) return true;

    for (int c = 1; c <= maxColor; c++) {
        if (isValid(node, c)) {
            color[node] = c;
            if (assignColor(node + 1, maxColor))
                return true;
            color[node] = 0; 
        }
    }
    return false;
}

int main() {
    cin >> n >> e;
    adj.assign(n, {});
    color.assign(n, 0);
    while (e--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int k = 1; k <= n; k++) {
        fill(color.begin(), color.end(), 0);
        if (assignColor(0, k)) {
            cout << k << endl;
            break;
        }
    }
}
