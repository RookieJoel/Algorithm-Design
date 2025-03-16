#include <bits/stdc++.h>
using namespace std;
 
const int INF = 1e9;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for(int i=0; i<N; i++){
        cin >> A[i];
    }
 
    vector<vector<int>> dp(N+1, vector<int>(M+1, INF));
    dp[0][0] = 0;
    for(int i = 1; i <= N; i++){
        for(int s = 0; s <= M; s++){
            if(dp[i-1][s] == INF) continue;
            for (int B = 1; B <= 100; B++){
                int add = B * B;
                if(s + add > M) break;
                dp[i][s + add] = min(dp[i][s+add], dp[i-1][s] + (A[i-1] - B) * (A[i-1] - B));
            }
        }
    }
    if(dp[N][M] == INF)
        cout << -1 << "\n";
    else
        cout << dp[N][M] << "\n";
 
    return 0;
}
