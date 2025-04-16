#include <bits/stdc++.h>
using namespace std;

vector<int> a;
int n, m, k;

void solve(int idx, int count, int total, int &ans) {
    if (count > m) return;
    if (idx == n) {
        if (count == m) {
            ans = min(ans, abs(k - total));
        }
        return;
    }
    solve(idx + 1, count + 1, total + a[idx], ans);
    solve(idx + 1, count, total, ans);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m >> k;
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int ans = INT_MAX;
    solve(0, 0, 0, ans);
    cout << ans;
}
