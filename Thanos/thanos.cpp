#include <bits/stdc++.h>
using namespace std;

void solve(vector<long long> &v, long long len, long long& total, int a, int b) {
    long long count = accumulate(v.begin(), v.end(), 0LL);

    if (len == 1) {
        total += (count == 0 ? a : b * count * len);
        return;
    }

    long long all = (count == 0 ? a : b * count * len);

    int mid = len >> 1;
    vector<long long> left(v.begin(), v.begin() + mid);
    vector<long long> right(v.begin() + mid, v.end());

    long long divide= 0;
    solve(left, mid, divide, a, b);
    solve(right, mid, divide, a, b);

    total += min(all, divide);
}

int main() {
    long long p, k, a, b;
    cin >> p >> k >> a >> b;
    long long len = pow(2, p);
    vector<long long> v(len, 0);

    for (int i = 0; i < k; i++) {
        long long x;
        cin >> x;
        v[x - 1] += 1;
    }

    long long total = 0;
    solve(v, len, total, a, b);
    cout << total << endl;

    return 0;
}
