#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

int main() {
    int v;
    cin >> v; 
    vector<vector<pair<ull,ull>>> adj(v); // adj[u] = {v,w}
    vector<ull> district(v);
    for(int i=0; i<v; i++){
        cin >> district[i];
    }

    for(int i=0; i<v-1; i++){
        for(int j=i+1; j<v; j++){
            ull weight = district[i] ^ district[j];
            adj[i].push_back({j, weight});
            adj[j].push_back({i, weight});
        }
    }

    vector<bool> visited(v, false);
    vector<ull> cost(v, 0);
    priority_queue<pair<ull,ull>> pq;
    pq.push({0, 0});
    ull total = 0;

    while(!pq.empty()){
        auto [weight, node] = pq.top(); pq.pop();
        if (visited[node]) continue; 

        visited[node] = true;
        total += weight;

        for(auto &[n, w] : adj[node]){
            if(!visited[n] && cost[n] < w){
                cost[n] = w;
                pq.push({w, n});
            }
        }
    }

    cout << total << endl;
}
