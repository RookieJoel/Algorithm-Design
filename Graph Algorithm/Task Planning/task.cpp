#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> adj(N);      // adj[u] = u->v
    vector<int> indeg(N, 0); 

    for (int i = 0; i < N; i++) {
        int M;
        cin >> M;
        for (int j = 0; j < M; j++) {
            int pre;
            cin >> pre;
            adj[pre].push_back(i);   //pre->i
            indeg[i]++;  
        }
    }
    // for (int i = 0; i < N; i++) {
    //     cout << "indeg[" << i << "] = " << indeg[i] << "\n";
    // }
    queue<int> q;
    for(int i=0;i<N;i++){
        if(indeg[i] == 0)q.push(i);
    }
    vector<int> ans;
    while(!q.empty()){
        int u = q.front();
        q.pop(); 
        ans.push_back(u);
        for(auto &v : adj[u]){
                indeg[v]--;
                if(indeg[v] == 0){
                    q.push(v);
                }
        }
    }

    for(auto &x : ans) cout << x << " ";
}
