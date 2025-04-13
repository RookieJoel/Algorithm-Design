#include <bits/stdc++.h>
using namespace std;

const int N = 4;
const vector<vector<int>> goal = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12},
    {13, 14, 15, 0}
};

int dx[] = {0, 0, 1, -1}; // ขวา ซ้าย ล่าง บน
int dy[] = {1, -1, 0, 0};

int manhattan(const vector<vector<int>> &board) {
    int dist = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            int val = board[i][j];
            if (val == 0) continue;
            int target_x = (val - 1) / N;
            int target_y = (val - 1) % N;
            dist += abs(i - target_x) + abs(j - target_y);
        }
    return dist;
}

struct State {
    vector<vector<int>> board;
    int g; // cost so far
    int f; // total cost = g + h
    int zx, zy; // position of zero

    bool operator>(const State &other) const {
        return f > other.f;
    }
};

int solve(vector<vector<int>> start) {
    int zx, zy;
    // หา position ของ 0
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (start[i][j] == 0)
                zx = i, zy = j;

    priority_queue<State, vector<State>, greater<>> pq;
    set<vector<vector<int>>> visited;

    int h = manhattan(start);
    pq.push({start, 0, h, zx, zy});
    visited.insert(start);

    while (!pq.empty()) {
        State curr = pq.top();
        pq.pop();

        if (curr.board == goal) return curr.g;

        for (int dir = 0; dir < 4; dir++) {
            int nx = curr.zx + dx[dir];
            int ny = curr.zy + dy[dir];
            if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;

            auto next_board = curr.board;
            swap(next_board[curr.zx][curr.zy], next_board[nx][ny]);

            if (visited.count(next_board)) continue;

            int h = manhattan(next_board);
            pq.push({next_board, curr.g + 1, curr.g + 1 + h, nx, ny});
            visited.insert(next_board);
        }
    }

    return -1; // ถ้าไม่มีวิธีแก้ (เช่น puzzle ไม่มีทางสำเร็จ)
}

int main() {
    vector<vector<int>> grid(4, vector<int>(4));
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            cin >> grid[i][j];

    cout << solve(grid) << endl;
}
