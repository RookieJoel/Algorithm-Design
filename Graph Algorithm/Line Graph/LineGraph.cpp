#include <bits/stdc++.h>
using namespace std;

bool bfs(int node, vector<vector<int>> &adj, vector<int> &visited,vector<int> &par) {
    queue<int> q;
    q.push(node);
    visited[node] = 1;
    bool flag = 0;
    int count = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto &v : adj[u]){
            if(!visited[v]){
                par[v] = u;
                visited[v] = 1;
                if(par[v] = node)count++;
            q.push(v); 
            }else if(v != par[v]){
                flag = 1;
                break;
            }
        }if(flag)break;
    }

    return flag || count > 2;
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
        if (adj[i].empty()) ans++;
    }

    vector<int> par(v);
    for (int i = 0; i < v; i++) {
        if(adj[i].size() > 2) continue;
        else if (!adj[i].empty() && !visited[i]) {
            if (!bfs(i, adj, visited,par)) ans++;
        }
    }

    cout << ans << "\n";
}
