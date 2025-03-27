#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    int target;
    cin >> target;

    vector<int> starts(k);
    for (int i = 0; i < k; ++i) {
        cin >> starts[i];
    }

    vector<vector<pair<int, int>>> revGraph(n);
    for (int i = 0; i < m; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        revGraph[b].emplace_back(a, w); 
    }
    vector<int> dist(n,INF);
    dist[target] = 0;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n;j++){
            for(auto &x :revGraph[j]){
                int v = x.first;
                int w = x.second;
                if(dist[j] != INF && dist[j]+w < dist[v]){
                    dist[v] = dist[j]+w;
                }
            }
        }
    }

    int ans = INT_MAX;
    for(auto &node : starts){
        ans = min(ans,dist[node]);
    }

    cout << ans;
}
