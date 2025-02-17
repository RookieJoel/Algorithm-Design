#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m, k;
    cin >> n >> m >> k;

    vector<ll> a(n), prefixSum(n + 1, 0);

    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        prefixSum[i + 1] = prefixSum[i] + a[i];
    }

    while (m--) {
        ll start, budget;
        cin >> start >> budget;

        ll low = start, high = n - 1, maxGrass = 0;

        while (low <= high) {
            ll mid = (low + high) / 2;
            ll slots = mid - start + 1;
            ll grassSum = prefixSum[mid + 1] - prefixSum[start];
            ll cost = grassSum + (slots * k);

            if (cost <= budget) {
                maxGrass = grassSum; 
                low = mid + 1;       
            } else {
                high = mid - 1;      
            }
        }

        cout << maxGrass << "\n";
    }

    return 0;
}
