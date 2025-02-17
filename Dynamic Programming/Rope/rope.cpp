#include <bits/stdc++.h>
using namespace std;

vector<int> mem;

int solve(int n, vector<int> &v) {
    if (n == 0) return 0; 
    if (mem[n] != -1) return mem[n];  

    int res = INT_MIN;
    for (auto &x : v) {
        if (n >= x) {  
            res = max(res, solve(n - x, v) + 1);
        }
    }

    return mem[n] = res;
}

int main() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    vector<int> v = {a, b, c};
    mem.assign(n + 1, -1);  

    int result = solve(n, v);
    cout << (result == INT_MIN ? 0 : result) << endl; 
}
