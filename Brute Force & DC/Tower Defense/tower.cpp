#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k, w;
    cin >> n >> m >> k >> w;

    vector<int> tower(n + 1, 0);  //hp
    vector<int> mon(m);          // mon pos
    vector<pair<int, int>> range(k); 

    for (int i = 0; i < m; i++) {
        cin >> mon[i];
    }

    for (int i = 0; i < m; i++) {
        int hp;
        cin >> hp;
        tower[mon[i]] += hp;
    }

    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        range[i].first = max(1, x - w);
        range[i].second = min(n, x + w);
    }

    for (const auto &x : range) {
        int a = x.first;
        int b = x.second;
        for (int i = a; i <= b; i++) {
            if (tower[i] != 0) {
                tower[i]--;
                break;
            }
        }
    }
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += tower[i];
    }
    cout << sum << "\n";
}
