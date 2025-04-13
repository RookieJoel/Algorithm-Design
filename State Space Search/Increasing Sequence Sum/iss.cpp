#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &seq, int idx, int target, int curSum, int &ans) {
    if (curSum == target) {
        ans++;
        // for (auto &x : seq) cout << x << " ";
        // cout << endl;
        return;
    }
    if (curSum > target) return;

    for (int i = idx; i <= target; i++) {
        if (curSum + i > target) break;
        seq.push_back(i); //debug only
        solve(seq, i, target, curSum + i, ans); 
        seq.pop_back();
    }
}

int main() {
    int target;
    cin >> target;
    vector<int> seq;
    int ans = 0;
    solve(seq, 1, target, 0, ans);
    cout << ans << endl;
}
