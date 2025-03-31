#include<bits/stdc++.h>

using namespace std; 

int main(){
    int n,m,k;
    cin >> n >> m >>k;
    vector<int> s(k+1);
    for(int i=1;i<=k;i++) cin >> s[i];
    vector<vector<int>> cost(n+1,vector<int>(n+1,INT_MAX));
    while(m--){
        int a,b,c;
        cin >> a >> b >> c;
        cost[a][b] = c;
        cost[b][a] = c;
    }

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i == j) cost[i][j] = 0;
    
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(cost[i][j] == 0) continue;
                if(cost[i][k] != INT_MAX && cost[k][j]!=INT_MAX){
                    cost[i][j] = min(cost[i][j],cost[i][k]+cost[k][j]);
                }
            }
        }
    }

    // cout << endl;
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         cout << cost[i][j] << " ";
    //         }cout << endl;
    //     }

    //below this lins are cooked by  ChatGPT
    // สมมติว่าคุณทำ Floyd-Warshall เสร็จแล้ว ได้ cost[i][j] แล้ว

int dp[1<<8][8]; // mask, last position
for(int i=0; i<(1<<k); i++) for(int j=0; j<k; j++) dp[i][j] = INT_MAX;

// base case: เริ่มที่สถานีใดก็ได้
for(int i=0; i<k; i++) dp[1<<i][i] = 0;

for(int mask=1; mask<(1<<k); mask++){
    for(int u=0; u<k; u++){
        if(!(mask & (1<<u))) continue;
        for(int v=0; v<k; v++){
            if(mask & (1<<v)) continue;
            int next = mask | (1<<v);
            dp[next][v] = min(dp[next][v], dp[mask][u] + cost[s[u+1]][s[v+1]]);
            // s[u+1] เพราะ s เริ่มจาก index 1
        }
    }
}

// หาค่าต่ำสุดที่ไปครบทุกสถานี
int ans = INT_MAX;
for(int i=0;i<k;i++) ans = min(ans, dp[(1<<k)-1][i]);
cout << ans << "\n";


}
    
