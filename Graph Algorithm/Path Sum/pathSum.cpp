#include<bits/stdc++.h>

using namespace std;
int n,m;

bool dfs(int node,int target, vector<vector<pair<int,int>>> &adj,int sum,vector<int> &visited){
    if(sum == target) return true;
    if(sum > target) return false;
    visited[node] = 1;
    for(auto &x : adj[node]){
        int v = x.first;
        int w = x.second;
        if(!visited[v]) if(dfs(v,target,adj,sum+w,visited)) return true;
    }
    visited[node] = 0;
    return false;
}

int main(){
    cin >> n >> m;
    vector<int> k(8);
    for(int i=0;i<8;i++) cin >> k[i];
    vector<vector<pair<int,int>>> adj(n); //adj[u] = {v,weight}
    while(m--){
        int a,b,w;
        cin >> a >> b >>w;
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }
    vector<int> visited(n);
    for(auto &target : k){
        bool flag = 0;
        for(int i=0;i<n;i++){
            if(dfs(i,target,adj,0,visited)){
                flag = 1;
                cout << "YES\n";
                break;
            }
        }if(!flag)cout << "NO\n";
    }

    
}