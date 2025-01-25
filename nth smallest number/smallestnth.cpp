#include <bits/stdc++.h>
using namespace std;

int partitionRandomized(vector<int> &arr, int left, int right) {
    int pivotIndex = left + rand() % (right - left + 1);
    swap(arr[pivotIndex], arr[right]);
    int pivot = arr[right];

    int i = left - 1;
    for (int j = left; j < right; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[right]);
    return i + 1;  
}

int quickSelect(vector<int> &arr, int left, int right, int m) {
    if (left == right) {
        return arr[left];
    }

    int p = partitionRandomized(arr, left, right);
    int k = p - left + 1; // no of elements in left partition (which is less than pivot)

    if (k == m) {
        return arr[p];
    }
    else if (m < k) { // mth smallest element is in left partition
        return quickSelect(arr, left, p - 1, m);
    }
    else {
        return quickSelect(arr, p + 1, right, m - k);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    srand(time(nullptr)); //use for random pivot

    int n, m;
    cin >> n >> m;   

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int ans = quickSelect(arr, 0, n - 1, m);
    cout << ans << "\n";

    return 0;
}
