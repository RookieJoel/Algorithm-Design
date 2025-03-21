#include<bits/stdc++.h>

using namespace std ;

int main(){
    int v,e,k;
    cin >> v >> e >> k;
    vector<int> visited;
    visited.resize(v+1);
    vector<vector<int>> adj(v+1);
    while(e--){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int count = 0;
    vector<int> dist(v+1);
    dist[0] = 0;
    queue<int> q;
    q.push(0);
    visited[0] = 1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        if(dist[u] > k) continue;
        for(auto &x : adj[u]){
            if(!visited[x]){
                visited[x] = 1;
                dist[x] = dist[u]+1;
                if(dist[x] == k)count++;
                q.push(x);
            }
        }
    }

    cout << count;


}