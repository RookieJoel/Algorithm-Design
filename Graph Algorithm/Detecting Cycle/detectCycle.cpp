#include<bits/stdc++.h>

using namespace std; 

bool cycleDetection(vector<vector<int>> &adj, vector<int> &visited, int node, int parent){
    visited[node] = 1;
    for(auto &x : adj[node]){
        if(visited[x] == 0){
            if(cycleDetection(adj,visited,x,node)) return true;
        }else if(x != parent){
            return true;
        }
    }
    return false;
}

int main(){ 
    int n; 
    cin >> n;
    while(n--){
        int v,e;
        cin >> v >> e; 
        vector<vector<int>> adj(v);
        vector<int> visited(v,0);
        for(int i =0;i<e;i++){
            int a,b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        int flag = false;
        for(int i=0;i<v;i++){
            if(visited[i] == 0){
                if(cycleDetection(adj,visited,i,-1)){
                    cout << "YES\n";
                    flag = true;
                    break;
                }
            }
        }
        if(!flag) cout << "NO\n";
    }
}