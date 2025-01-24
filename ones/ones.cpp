#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <climits>

using namespace std;

// Memoization map to optimize recursive calls
unordered_map<int, int> memo;

// Recursive function to calculate the minimal number of digits "1"
int minimalOnes(int n) {
    // Base case: if n is 0, no digits are needed
    if (n == 0) return 0;

    // Check if already computed
    if (memo.count(n)) return memo[n];

    // Generate all q_k values (1, 11, 111, ...) up to |n|
    vector<int> q_values;
    long long q = 1;
    while (q <= abs(n)) {
        q_values.push_back(q);
        q = q * 10 + 1; // Generate the next q_k
    }

    int min_count = INT_MAX;

    // Try each q_k
    for (auto qk : q_values) {
        // Positive contribution
        int count_positive = n / qk + minimalOnes(n % qk);
        min_count = min(min_count, count_positive);

        // Negative contribution
        int count_negative = abs(n / qk) + minimalOnes(n % qk + qk);
        min_count = min(min_count, count_negative);
    }

    // Store the result in memoization map
    return memo[n] = min_count;
}

int main() {
    // Input: Read n
    int n;
    cin >> n;

    // Output: Minimal number of digits "1"
    cout << minimalOnes(n) << endl;

    return 0;
}
