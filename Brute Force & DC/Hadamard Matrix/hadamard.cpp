#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> solve(vector<ll>& v) {
    int n = v.size();
    if (n == 1) return v; // H1*v = v; [1] * V = V;

    int half = n / 2;
    vector<ll> v_top(half), v_bottom(half);

    for (int i = 0; i < half; i++) {
        v_top[i] = v[i] + v[i + half];   // top * v
        v_bottom[i] = v[i] - v[i + half]; // bottom * v
    }

    vector<ll> res_top = solve(v_top);
    vector<ll> res_bottom = solve(v_bottom);

    vector<ll> result(n);
    for (int i = 0; i < half; i++) {
        result[i] = res_top[i];
        result[i + half] = res_bottom[i];
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<ll> result = solve(v);

    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
