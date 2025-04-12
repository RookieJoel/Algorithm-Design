#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long path(int x, int y, const vector<long long>& t, long long sum) {
    if (x > y) swap(x, y);
    return min(t[y] - t[x], sum - (t[y] - t[x]));
}

long long dis(int x, int y, int u, int v, const vector<long long>& t, long long sum) {
    long long ans = path(x, y, t, sum);
    ans = min(ans, path(x, u, t, sum) + path(v, y, t, sum));
    ans = min(ans, path(x, v, t, sum) + path(u, y, t, sum));
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    cin >> m >> n;

    vector<int> a(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    a[n] = a[0]; // วนกลับ

    vector<long long> t(n + 1, 0); // prefix sum
    long long sum = 0;

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        sum += x;
        t[i] = t[i - 1] + x;
    }

    while (m--) {
        int u, v;
        cin >> u >> v;
        long long total_dist = 0;
        for (int i = 1; i <= n; i++) {
            total_dist += dis(a[i], a[i - 1], u, v, t, sum);
        }
        cout << total_dist << '\n';
    }

    return 0;
}
