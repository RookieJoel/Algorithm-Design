#include<bits/stdc++.h>
using namespace std;

int solve(int n, int l, int r, int left, int right) {
    if (n <= 1) {
        // Base case: if n is 0 or 1, return it if it falls within the range [l, r]
        if (l <= left && right <= r) return n;
        return 0;
    }
    
    int mid = (left + right) / 2;
    int sum = 0;

    // Recur on the left half if [l, r] overlaps with the left half
    if (l <= mid) {
        sum += solve(n / 2, l, r, left, mid - 1);
    }

    // Process the middle element if it falls within [l, r]
    if (l <= mid && mid <= r) {
        sum += n % 2;
    }

    // Recur on the right half if [l, r] overlaps with the right half
    if (r > mid) {
        sum += solve(n / 2, l, r, mid + 1, right);
    }

    return sum;
}

int main() {
    int n, l, r;
    cin >> n >> l >> r;

    // Calculate the range size of the full sequence
    int size = 1;
    int temp = n;
    while (temp > 1) {
        size = size * 2 + 1;
        temp /= 2;
    }

    // Call the optimized solve function
    int result = solve(n, l, r, 1, size);
    cout << result;

    return 0;
}
