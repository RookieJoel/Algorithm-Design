#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,e,s;
    cin >> n >> e >> s; 
    vector<vector<pair<int,int>>> adj(n); // adj[u] = {v, weight}
    for(int i=0;i<e;i++){
        int a,b,c;
        cin >> a >> b >> c; 
        adj[a].push_back({b,c});
    }

    vector<int> dist(n,INT_MAX);
    dist[s] = 0;

    // Relax
    for(int i = 0; i < n - 1; i++) {
        for(int u = 0; u < n; u++) {
            if(dist[u] == INT_MAX) continue;
            for(int j = 0; j < adj[u].size(); j++) {
                int v = adj[u][j].first;
                int w = adj[u][j].second;
                if(dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                }
            }
        }
    }

    //neg cycle
    for(int u = 0; u < n; u++) {
        if(dist[u] == INT_MAX) continue;
        for(int j = 0; j < adj[u].size(); j++) {
            int v = adj[u][j].first;
            int w = adj[u][j].second;
            if(dist[u] + w < dist[v]) {
                cout << -1 << endl;
                return 0;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        cout << dist[i] << " ";
    }
    cout << endl;

    return 0;
}
