#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> w(n + 1, vector<int>(n + 1));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> w[i][j];
        }
    }

    vector<int> cost(n + 1, INT_MAX);
    set<pair<int,int>> s;
    cost[1] = 0;
    s.insert({0,1});
    while(!s.empty()){
        auto u = *s.begin();
        int weight = u.first;
        int node = u.second; 
        s.erase(u);

        for(int i=1; i<=n; i++){
            if(w[node][i] == -1 || w[node][i] == 0) continue;
            if(cost[i] > weight + w[node][i]){
                cost[i] = weight + w[node][i];
                s.insert({cost[i], i});
            }
        }
    }

    int ans = INT_MIN;
    for(int i=1; i<=n; i++){
        if (cost[i] == INT_MAX) {
            cout << -1;
            return 0;
        }
        ans = max(ans, cost[i]);
    }
    cout << ans;
}
