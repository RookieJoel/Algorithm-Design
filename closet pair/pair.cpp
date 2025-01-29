#include <bits/stdc++.h>
#define ll long long
using namespace std;

// Point structure
struct Point {
    int x, y;
};

// Comparator for sorting by x-coordinate
bool compareX(const Point &a, const Point &b) {
    return a.x < b.x;
}

// Comparator for sorting by y-coordinate
bool compareY(const Point &a, const Point &b) {
    return a.y < b.y;
}

// Function to calculate squared distance between two points
ll squaredDistance(const Point &a, const Point &b) {
    return 1LL * (a.x - b.x) * (a.x - b.x) + 1LL * (a.y - b.y) * (a.y - b.y);
}

// Brute force method to calculate minimum distance in a small set of points
ll bruteForce(const vector<Point> &points, int left, int right) {
    ll minDist = LLONG_MAX;
    for (int i = left; i <= right; i++) {
        for (int j = i + 1; j <= right; j++) {
            minDist = min(minDist, squaredDistance(points[i], points[j]));
        }
    }
    return minDist;
}

// Function to find the minimum distance in a strip
ll stripClosest(vector<Point> &strip, ll d) {
    ll minDist = d;
    sort(strip.begin(), strip.end(), compareY); // Sort by y-coordinate
    int size = strip.size();

    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size && (strip[j].y - strip[i].y) * (strip[j].y - strip[i].y) < minDist; j++) {
            minDist = min(minDist, squaredDistance(strip[i], strip[j]));
        }
    }
    return minDist;
}

// Recursive function to find the closest pair
ll closestPair(vector<Point> &points, int left, int right) {
    if (right - left <= 3) {
        return bruteForce(points, left, right); // Use brute force for small subsets
    }

    int mid = (left + right) / 2;
    Point midPoint = points[mid];

    ll d_left = closestPair(points, left, mid);
    ll d_right = closestPair(points, mid + 1, right);
    ll d = min(d_left, d_right);

    // Create a strip of points near the dividing line
    vector<Point> strip;
    for (int i = left; i <= right; i++) {
        if (abs(points[i].x - midPoint.x) * abs(points[i].x - midPoint.x) < d) {
            strip.push_back(points[i]);
        }
    }

    return min(d, stripClosest(strip, d));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<Point> points(n);

    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    // Sort points by x-coordinate
    sort(points.begin(), points.end(), compareX);

    // Find the minimum squared distance using divide and conquer
    ll minDist = closestPair(points, 0, n - 1);

    cout << minDist << "\n";
    return 0;
}
