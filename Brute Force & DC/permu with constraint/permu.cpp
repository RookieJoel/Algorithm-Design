#include <bits/stdc++.h>
using namespace std;

bool isValid(vector<int> &sol, vector<pair<int, int>> &p, int len) {
    for (auto &constraint : p) {
        int a = constraint.first;
        int b = constraint.second;
        bool foundA = false, foundB = false;
        for (int i = 0; i < len; i++) {
            if (sol[i] == a) foundA = true;
            if (sol[i] == b) foundB = true;
            if (foundB && !foundA) return false; // b comes before a
        }
    }
    return true;
}



void permu(vector<int> &sol, vector<int> &used, int n, int len, vector<pair<int, int>> &p, int index) {
    if (len < n) {
        for (int i = 0; i < n; i++) {
            if (!used[i]) { // Do not pick an item that is already used
                sol[len] = i;
                if (isValid(sol, p, len + 1)) {
                    used[i] = true;
                    permu(sol, used, n, len + 1, p, index);
                    used[i] = false;
                }
            }
        }
    } else {
        for (int i = 0; i < n; i++) cout << sol[i] << " ";
        cout << "\n"; 
    }
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m; 
    scanf("%d %d", &n, &m);
    vector<pair<int, int>> p(m);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        p[i] = {a, b};
    }
    vector<int> sol(n), used(n, false);
    permu(sol, used, n, 0, p, 0);
    return 0;
}
