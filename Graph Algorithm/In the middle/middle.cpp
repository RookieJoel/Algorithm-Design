#include<bits/stdc++.h>
using namespace std;

vector<int> dist1, dist2, dist3;

void bfs(queue<int> q, vector<vector<int>> &e, vector<int> &dist, int n){
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(auto &v : e[u]){
            if(dist[v] == -1){
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

int main(){
    int n, t1, t2, t3;
    cin >> n >> t1 >> t2 >> t3;
    vector<vector<int>> e(n+1);
    dist1.assign(n+1, -1);
    dist2.assign(n+1, -1);
    dist3.assign(n+1, -1);

    for(int i = 1; i <= n; i++){
        int k;
        cin >> k;
        while(k--){
            int a; cin >> a;
            e[i].push_back(a);
        }
    }

    dist1[t1] = 0;
    dist2[t2] = 0;
    dist3[t3] = 0;

    queue<int> q1, q2, q3;
    q1.push(t1);
    q2.push(t2);
    q3.push(t3);

    bfs(q1, e, dist1, n);
    bfs(q2, e, dist2, n);
    bfs(q3, e, dist3, n);

    int ans = INT_MAX;
    for(int i = 1; i <= n; i++){
        if(dist1[i] != -1 && dist2[i] != -1 && dist3[i] != -1){
            int Max = max({dist1[i], dist2[i], dist3[i]});
            ans = min(ans, Max);
        }
    }

    cout << ans << endl;
}
