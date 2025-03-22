#include<bits/stdc++.h>

using namespace std;
int n,m,k;
int bellman(int start,vector<vector<pair<int,int>>> &adj,int target){
    vector<int> dist(n,INT_MAX);
    dist[start] = 0;
    //relax
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n;j++){
            if(dist[j] == INT_MAX) continue;
            for(auto &x : adj[j]){
                int v = x.first;
                int w = x.second;
                if(dist[j]+w < dist[v]){
                    dist[v] = dist[j]+w;
                }
            }
        }
    }

    return dist[target];
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin >> n>>m>>k;
    int target;
    cin >> target;
    vector<int> candidate(k);
    for(int i=0;i<k;i++) cin >> candidate[i];
    vector<vector<pair<int,int>>> adj(n); //adj[u] = {v,weight}
    while(m--){
        int a,b,c;
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
    }   
    int ans = INT_MAX;
    for(auto &c : candidate){
        int x = bellman(c,adj,target);
        ans = min(ans,x);
    }

    cout << ans;
}