#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll solve(ll n, ll r, ll c, ll u, ll v, ll w, ll p) {
    if (n == 1) {
        // Base case: M1
        if (r == 0 && c == 0) return u; // Top-left
        if (r == 0 && c == 1) return v; // Top-right
        if (r == 1 && c == 0) return w; // Bottom-left
        if (r == 1 && c == 1) return p; // Bottom-right
    }

    ll size = 1LL << (n - 1); // Half the size of the matrix at level n

    if (r < size && c < size) {
        // Q1: Top-left quadrant
        return solve(n - 1, r, c, u, v, w, p);
    } else if (r < size && c >= size) {
        // Q2: Top-right quadrant (transpose)
        return solve(n - 1, r, c - size, u, w, v, p);
    } else if (r >= size && c < size) {
        // Q3: Bottom-left quadrant (negation)
        return -solve(n - 1, r - size, c, -u, -v, -w, -p);
    } else {
        // Q4: Bottom-right quadrant (negation and transpose)
        return -solve(n - 1, r - size, c - size, -u, -w, -v, -p);
    }
}

int main() {
    ll n, m;
    cin >> n >> m; // Input n (matrix level) and m (number of queries)

    ll u, v, w, p;
    cin >> u >> v >> w >> p; // Input values for M1

    while (m--) {
        ll r, c;
        cin >> r >> c; // Input query row and column
        r--; c--; // Convert to 0-based indexing
        cout << solve(n, r, c, u, v, w, p) << "\n";
    }

    return 0;
}
