#include <bits/stdc++.h>
using namespace std;

void recur(vector<vector<int>> &v, int a, int b, int top, int bottom, int left, int right) {
    if (a == 0) { 
        v[top][left] = b;
        return;
    }
    int midRow = (top + bottom) / 2; 
    int midCol = (left + right) / 2; 
    cout << midRow << " : " << midCol << endl;
    //H(a-1, b)
    recur(v, a - 1, b, top, midRow, left, midCol);

    //H(a-1, b-1)
    recur(v, a - 1, b - 1, top, midRow, midCol, right);

    //H(a-1, b+1)
    recur(v, a - 1, b + 1, midRow, bottom, left, midCol);

    //H(a-1, b)
    recur(v, a - 1, b, midRow, bottom, midCol, right);
}

int main() {
    int a, b;
    cin >> a >> b;
    int size = 1 << a; 
    vector<vector<int>> grid(size, vector<int>(size));
    recur(grid, a, b, 0, size, 0, size);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
