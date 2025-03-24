int dp[1 << N][N];
for (int i = 0; i < (1 << N); i++)
    for (int j = 0; j < N; j++)
        dp[i][j] = -INF;

dp[1 << 0][0] = 0; // เริ่มที่เมือง 0

for (int mask = 0; mask < (1 << N); mask++) {
    for (int u = 0; u < N; u++) {
        if (!(mask & (1 << u))) continue;

        for (int v = 0; v < N; v++) {
            if (mask & (1 << v)) continue;
            int next = mask | (1 << v);
            dp[next][v] = max(dp[next][v], dp[mask][u] + w[u][v]);
        }
    }
}

cout << dp[(1 << N) - 1][N - 1]; // ไปครบทุกเมือง และจบที่เมือง N-1
