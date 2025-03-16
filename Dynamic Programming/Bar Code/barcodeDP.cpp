#include <bits/stdc++.h>
using namespace std;

int memo[31][2][31][31];

int dp(int pos, int col, int run, int chg, int N, int M, int K) {
    if (memo[pos][col][run][chg] != -1) return memo[pos][col][run][chg];
    if (pos == N) return (chg == K) ? 1 : 0;
    int ways = 0;
    if (run < M) ways += dp(pos+1, col, run+1, chg, N, M, K);
    if (chg < K) ways += dp(pos+1, 1-col, 1, chg+1, N, M, K);
    memo[pos][col][run][chg] = ways;
    return ways;
}

int main(){
    int N, M, K;
    cin >> N >> M >> K;
    memset(memo, -1, sizeof(memo));
    int ans = dp(1, 0, 1, 0, N, M, K);
    cout << ans << "\n";
    return 0;
}
