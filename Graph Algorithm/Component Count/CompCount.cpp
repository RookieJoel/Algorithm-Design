#include<bits/stdc++.h>

using namespace std;

void bfs(int start, vector<vector<int>> &adj, vector<int> &visited){
    queue<int> q;
    q.push(start);
    visited[start] = 1;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto &x : adj[node]){
            if(visited[x] == 0){
                visited[x] = 1;
                q.push(x);
            }
        }
    }
}

int main(){
    int v,e;
    cin >> v >> e; 
    vector<vector<int>> adj(v+1);
    vector<int> visited(v+1,0);
    for(int i =0;i<e;i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int count = 0; 
    for(int i =1;i<=v;i++){
        if(visited[i] == 0){
            bfs(i,adj,visited);
            count++;
        }
    }

    cout << count << endl;
}