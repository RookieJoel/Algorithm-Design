#include <bits/stdc++.h>
using namespace std;
                                                                    // use this, it make this code less memory
void path(vector<vector<int>> &grid, int r, int c, int x, int y, string &s) {
    if (x == r - 1 && y == c - 1) {
        cout << s << "\n";
        return;
    }
    // Mark 
    grid[x][y] = 1;

    // A = right
    if (y + 1 < c && grid[x][y + 1] == 0) {
        s.push_back('A');
        path(grid, r, c, x, y + 1, s);
        s.pop_back();  
    }

    // B = Down
    if (x + 1 < r && grid[x + 1][y] == 0) {
        s.push_back('B');
        path(grid, r, c, x + 1, y, s);
        s.pop_back(); 
    }
    
    //C = up
    if(x-1 >= 0 && grid[x-1][y] == 0){ 
        s.push_back('C');
        path(grid,r,c,x-1,y,s);
        s.pop_back(); 
    }
    // Unmark 
    grid[x][y] = 0;
}

int main() {
    int r, c;
    cin >> r >> c;

    vector<vector<int>> grid(r, vector<int>(c));

    // Input grid
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> grid[i][j];
        }
    }

    string s = "";  
    path(grid, r, c, 0, 0, s);

    cout << "DONE\n";

    return 0;
}
