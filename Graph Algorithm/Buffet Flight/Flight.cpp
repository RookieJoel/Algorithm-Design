#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int v,e;
    cin >> v >> e;
    vector<int> ci(v),co(v);
    for(int i=0;i<v;i++) cin >> ci[i];
    for(int i=0;i<v;i++) cin >> co[i];
    vector<vector<pair<int,int>>> adj(v); //adj[u] = {v,cost}
    vector<int> cost(v,INT_MAX);
    while(e--){
        int a,b;
        cin >> a >> b;
        adj[a].push_back({b,co[a]+ci[b]});
    }
    set<pair<int,int>> s; 
    cost[0]= 0;
    s.insert({0,0}); // {w,node}
    while(!s.empty()){
        auto u = *s.begin();
        int w = u.first;
        int n = u.second;
        s.erase(u);
        for(auto &x : adj[n]){
            int vertex = x.first;
            int weight = x.second;
            if(cost[vertex] > cost[n]+weight){
                auto it = s.find({cost[vertex], vertex});
                if (it != s.end()) s.erase(it);
                cost[vertex] = cost[n]+weight;
                s.insert({cost[vertex], vertex});

            }
        }
    }

    for (int i = 0; i < v; ++i) {
        if (cost[i] == INT_MAX) cout << -1 << " ";
        else cout << cost[i] << " ";
    }
    cout << "\n";
            
        
    
}