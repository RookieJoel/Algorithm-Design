#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops,fast-math")
using namespace std;

vector<int> parent(2000);
int bfs(int node,vector<vector<int>> &adj,vector<int> &c){
    queue<int> q; 
    q.push(node);
    int maxDif = INT_MIN;
    while(!q.empty()){
        int cur = q.front();
        q.pop(); 
        for(auto &n: adj[cur]){
            parent[n] = cur; 
            int i = n;
            int dif = 0;
            while(i > 0){
                int par = parent[i];
                dif = max({dif,c[n]-c[par]});
                i = par;
            }
            maxDif = max(maxDif,dif);
            q.push(n);
        }   
    }

    return maxDif;
}

int main(){
    int v,e;
    cin >> v >> e;
    vector<int> c(v);
    for(int i=0;i<v;i++) cin >> c[i];
    vector<vector<int>> adj(v);
    while(e--){
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
    }

    cout << bfs(0,adj,c);

}