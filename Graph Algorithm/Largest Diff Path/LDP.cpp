#include <bits/stdc++.h>

using namespace std;

int findLargestDiffPath(int n, vector<int>& c, vector<vector<int>>& adj) {
    vector<int> inDegree(n, 0);  
    vector<int> minValue = c;    
    int maxDiff = 0;       

    for (int i = 0; i < n; i++) {
        for (int neighbor : adj[i]) {
            inDegree[neighbor]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : adj[node]) {
            minValue[neighbor] = min(minValue[neighbor], minValue[node]);  
            maxDiff = max(maxDiff, c[neighbor] - minValue[neighbor]);      

            if (--inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    return maxDiff;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    
    vector<int> c(n);
    for (int i = 0; i < n; i++) cin >> c[i];

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }

    cout << findLargestDiffPath(n, c, adj) << "\n";
    return 0;
}

