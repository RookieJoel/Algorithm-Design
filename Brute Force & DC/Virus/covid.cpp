#include <bits/stdc++.h>
using namespace std;

bool isVirus(vector<int>& v, int start, int stop) {
    if (stop - start == 1) {
        return (v[start] == 0 && v[stop] == 1);
    }

    int mid = (start + stop) / 2;

    bool left = isVirus(v, start, mid);
    bool right = isVirus(v, mid + 1, stop);

    vector<int> reversed(mid - start + 1);
    for (int i = 0; i <= mid - start; i++) {
        reversed[i] = v[mid - i];
    }
    bool rev = isVirus(reversed, 0, mid - start);

    return (left && right) || (rev && right);
}

int main() {
    int n, k;
    cin >> n >> k;
    int len = pow(2, k);

    for (int i = 0; i < n; i++) {
        vector<int> v(len);
        for (int j = 0; j < len; j++) {
            cin >> v[j];
        }
        isVirus(v, 0, len - 1) ? cout << "yes\n" : cout << "no\n";
    }

    return 0;
}
