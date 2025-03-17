#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    
    vector<vector<int>> adj(n, vector<int>(n)); 
    vector<int> degree_count(n + 1, 0); 
    int max_degree = 0;

    for (int i = 0; i < n; i++) {
        int degree = 0;
        for (int j = 0; j < n; j++) {
            cin >> adj[i][j];
            if (adj[i][j] == 1) degree++; 
        }
        degree_count[degree]++;
        max_degree = max(max_degree, degree); 
    }

    for (int i = 0; i <= max_degree; i++) {
        cout << degree_count[i] << " ";
    }

}
