#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

const int MAX = 1005;
int R, C;
int grid[MAX][MAX];
bool visited[MAX][MAX];
bool inStack[MAX][MAX];
int maxLength = 0, loopCount = 0;

vector<pair<int, int>> directions[7]; // ถนนแบบ 1-6

bool isConnected(int type, int dr, int dc) {
    for (auto [ndr, ndc] : directions[type]) {
        if (ndr == -dr && ndc == -dc) return true;
    }
    return false;
}

int dfs(int r, int c, int pr, int pc, vector<vector<pair<int, int>>>& path) {
    visited[r][c] = true;
    inStack[r][c] = true;

    int length = 1;

    for (auto [dr, dc] : directions[grid[r][c]]) {
        int nr = r + dr, nc = c + dc;

        if (nr < 1 || nr > R || nc < 1 || nc > C) continue;
        if (!isConnected(grid[nr][nc], dr, dc)) continue;

        if (!visited[nr][nc]) {
            path[nr][nc] = {r, c};
            dfs(nr, nc, r, c, path);
        }
        else if (inStack[nr][nc] && !(nr == pr && nc == pc)) {
            // พบวงวน
            int loopLen = 1;
            int tr = r, tc = c;
            while (!(tr == nr && tc == nc)) {
                tie(tr, tc) = path[tr][tc];
                loopLen++;
            }
            if (loopLen >= 2) { // ✅ กันวงวนปลอม
                loopCount++;
                maxLength = max(maxLength, loopLen);
            }
        }
    }

    inStack[r][c] = false;
    return length;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> R >> C;
    if(R == 1) {
      cout << "0 0";
      return 0;
    }
    // ทิศของถนนแต่ละแบบ
    directions[1] = {{0, -1}, {0, 1}};     // ซ้าย ↔ ขวา
    directions[2] = {{-1, 0}, {1, 0}};     // บน ↕ ล่าง
    directions[3] = {{-1, 0}, {0, 1}};     // บน ↔ ขวา
    directions[4] = {{0, 1}, {1, 0}};      // ขวา ↔ ล่าง
    directions[5] = {{1, 0}, {0, -1}};     // ล่าง ↔ ซ้าย
    directions[6] = {{0, -1}, {-1, 0}};    // ซ้าย ↔ บน

    for (int i = 1; i <= R; ++i)
        for (int j = 1; j <= C; ++j)
            cin >> grid[i][j];

    vector<vector<pair<int, int>>> path(MAX, vector<pair<int, int>>(MAX, {-1, -1}));

    for (int i = 1; i <= R; ++i)
        for (int j = 1; j <= C; ++j)
            if (!visited[i][j])
                dfs(i, j, -1, -1, path);

    if (loopCount == 0)
        cout << "0\n";
    else
        cout << loopCount << " " << maxLength << "\n";

    return 0;
}
