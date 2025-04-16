#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> price;
vector<vector<int>> books;
int ans = INT_MAX;

vector<int> sorted_idx;

void dfs(int idx, int total, vector<bool>& have, int count) {
    if (total >= ans) return; 
    if (count == n) {
        ans = total;
        return;
    }
    if (idx == k) return;

    int i = sorted_idx[idx];

    if (total + price[i] >= ans) return; 

    // take
    vector<int> added;
    for (int b : books[i]) {
        if (!have[b]) {
            have[b] = true;
            added.push_back(b);
            count++;
        }
    }
    dfs(idx + 1, total + price[i], have, count);

    // dont take
    for (int b : added) {
        have[b] = false;
        count--;
    }
    dfs(idx + 1, total, have, count);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> k;
    price.resize(k);
    books.resize(k);
    for (int i = 0; i < k; i++) {
        int p, m;
        cin >> p >> m;
        price[i] = p;
        books[i].resize(m);
        for (int j = 0; j < m; j++) {
            int book;
            cin >> book;
            books[i][j] = book - 1; // 0-based
        }
    }

    sorted_idx.resize(k);
    iota(sorted_idx.begin(), sorted_idx.end(), 0);
    sort(sorted_idx.begin(), sorted_idx.end(), [&](int a, int b) {
        return price[a] < price[b];
    });

    vector<bool> have(n, false);
    dfs(0, 0, have, 0);
    cout << ans << '\n';
}
