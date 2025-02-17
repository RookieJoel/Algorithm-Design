#include <bits/stdc++.h>
using namespace std;

long long solve(vector<long long>& v, long long l, long long r, int a, int b) {
    long long count = upper_bound(v.begin(), v.end(), r) - lower_bound(v.begin(), v.end(), l);
    if (count == 0) return a;

    long long all = (r - l + 1) * count * b;

    if (l == r) return all;

    long long mid = (l + r) / 2;

    long long left = solve(v, l, mid, a, b);
    long long right = solve(v, mid + 1, r, a, b);

    return min(all, left + right);
}

int main() {
    int p, k, a, b;
    cin >> p >> k >> a >> b;

    long long len = (1LL << p); 
    vector<long long> v;

    for (int i = 0; i < k; i++) {
        long long x;
        cin >> x;
        v.push_back(x - 1);
    }

    sort(v.begin(), v.end());
    cout << solve(v, 0, len - 1, a, b) << endl;

    return 0;
}
