#include <bits/stdc++.h>

using namespace std;

bool isSimilar(const string &a, const string &b, int startA, int startB, int len) {
    if (len == 1) return a[startA] == b[startB];

    int mid = len / 2;

    return (isSimilar(a, b, startA, startB, mid) && isSimilar(a, b, startA + mid, startB + mid, mid)) || 
           (isSimilar(a, b, startA, startB + mid, mid) && isSimilar(a, b, startA + mid, startB, mid));
}

int main() {
    string a, b;
    cin >> a >> b;
    
    if (isSimilar(a, b, 0, 0, a.length())) cout << "YES\n";
    else cout << "NO\n";
    
    return 0;
}
