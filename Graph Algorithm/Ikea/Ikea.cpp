#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, e;
    cin >> n >> e;

    vector<unordered_set<int>> prereq(n + 1);

    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        prereq[b].insert(a);
    }

    for (int i = 0; i < 5; i++) {
        vector<int> plan(n);
        unordered_set<int> done;
        for (int j = 0; j < n; j++) {
            cin >> plan[j];
        }

        bool ok = true;
        for (int j = 0; j < n; j++) {
            int step = plan[j];
            for (int pre : prereq[step]) {
                if (!done.count(pre)) {
                    ok = false;
                    break;
                }
            }
            if (!ok) break;
            done.insert(step);
        }

        cout << (ok ? "SUCCESS" : "FAIL") << "\n";
    }
}
