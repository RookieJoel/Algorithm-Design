#include <bits/stdc++.h>
using namespace std;

int maxCrossingSum(vector<int>& arr, int left, int mid, int right) {
    int left_sum = INT_MIN, right_sum = INT_MIN;
    int sum = 0;

    for (int i = mid; i >= left; i--) {
        sum += arr[i];
        left_sum = max(left_sum, sum);
    }

    sum = 0;
    for (int i = mid + 1; i <= right; i++) {
        sum += arr[i];
        right_sum = max(right_sum, sum);
    }

    return left_sum + right_sum;
}

int maxSubarraySum(vector<int>& arr, int left, int right) {
    if (left == right) return arr[left]; 

    int mid = (left + right) / 2;

    int l = maxSubarraySum(arr, left, mid);
    int r = maxSubarraySum(arr, mid + 1, right);
    int m = maxCrossingSum(arr, left, mid, right);

    return max({l, r, m});
}

// Function to compute max circular subarray sum using divide and conquer
int maxCircularSubarraySum(vector<int>& arr) {
    int n = arr.size();

    // Case 1: Normal max subarray sum (non-circular)
    int max_normal = maxSubarraySum(arr, 0, n - 1);

    // Case 2: Max circular subarray sum
    int total_sum = accumulate(arr.begin(), arr.end(), 0);
    
    // Invert array to find the minimum subarray sum
    for (int i = 0; i < n; i++) arr[i] = -arr[i];

    // Find min subarray sum using divide and conquer
    int min_subarray_sum = maxSubarraySum(arr, 0, n - 1);
    
    // Restore array values
    for (int i = 0; i < n; i++) arr[i] = -arr[i];

    int max_circular = total_sum + min_subarray_sum; // Circular max sum

    // If all numbers are negative, return max_normal
    if (max_circular == 0) return max_normal;

    return max(max_normal, max_circular);
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << maxCircularSubarraySum(arr) << endl;
    return 0;
}
