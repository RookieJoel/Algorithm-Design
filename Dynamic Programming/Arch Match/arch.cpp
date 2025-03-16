#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    // ใช้ index เริ่มต้นที่ 1 เพื่อให้ง่ายต่อการเขียน DP
    vector<int> A(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> A[i];
    }
    
    // dp[i][j] คือคะแนนรวมสูงสุดที่จับคู่ได้ในช่วงตำแหน่ง i ถึง j
    // สำหรับกรณีที่ i > j เราจะถือว่า dp[i][j] = 0
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
    
    // เติม dp แบบ bottom-up
    // พิจารณาช่วงจากตำแหน่ง i ถึง j โดย i ลดลงจาก n ไป 1
    for (int i = n; i >= 1; i--){
        // j ต้องมากกว่า i อย่างน้อย 1 เพราะต้องมีคู่จับได้
        for (int j = i + 1; j <= n; j++){
            // กรณีที่ไม่จับคู่ตำแหน่ง i กับตำแหน่งใดเลย
            dp[i][j] = dp[i + 1][j];
            // ลองจับคู่ตำแหน่ง i กับตำแหน่ง k (i < k ≤ j)
            for (int k = i + 1; k <= j; k++){
                // คะแนนจากการจับคู่ i กับ k คือ A[i] * A[k]
                // ส่วน dp[i+1][k-1] คือคะแนนที่ดีที่สุดจากส่วนที่อยู่ระหว่าง i กับ k
                // ส่วน dp[k+1][j] คือคะแนนที่ดีที่สุดจากส่วนที่เหลือทางขวาของ k
                int candidate = A[i] * A[k] + dp[i + 1][k - 1] + dp[k + 1][j];
                dp[i][j] = max(dp[i][j], candidate);
            }
        }
    }

    for(int i =0;i<n+2;i++){
        for(int j=0;j<n+2;j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    
    // คำตอบสุดท้ายคือ dp[1][n] ซึ่งคือคะแนนรวมสูงสุดที่จับคู่ได้จากทั้งแถว
    cout << dp[1][n] << "\n";
    
    return 0;
}
