#include <bits/stdc++.h>
using namespace std;

// อ่าน n,w
// อ่าน l[i], r[i]  (0-based หรือ 1-based ก็ได้ แต่อันนี้ใช้ 0-based)

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, w, k;
    cin >> n >> w >> k; // k ใช้ไม่ได้ในที่นี้ (k=n) -- เราไม่ใช้

    vector<long long> L(n), R(n);
    for(int i = 0; i < n; i++){
        cin >> L[i];
    }
    for(int i = 0; i < n; i++){
        cin >> R[i];
    }

    // dpLeft[i] = ค่าสูงสุดของการเลือก billboard จบที่ i ฝั่งซ้าย
    // dpRight[i] = ค่าสูงสุดของการเลือก billboard จบที่ i ฝั่งขวา

    // bestLeft[i] = max ของ dpLeft[0..i]
    // bestRight[i] = max ของ dpRight[0..i]

    vector<long long> dpLeft(n, 0), dpRight(n, 0);
    vector<long long> bestLeft(n, 0), bestRight(n, 0);

    // กำหนด dpLeft[0], dpRight[0] เริ่มต้น
    dpLeft[0]  = L[0];  
    dpRight[0] = R[0];
    bestLeft[0]  = dpLeft[0];
    bestRight[0] = dpRight[0];

    for(int i = 1; i < n; i++){
        // 1) dpLeft[i]
        {
            // base = l[i], บวกค่าจาก bestRight[p] ที่ p <= i - (w+1)
            long long val = (long long)L[i];
            int p = i - w - 1;
            if(p >= 0){
                val += bestRight[p]; // เพราะ bestRight[p] = max(dpRight[0..p])
            }
            dpLeft[i] = val; 
        }

        // 2) dpRight[i]
        {
            long long val = (long long)R[i];
            int p = i - w - 1;
            if(p >= 0){
                val += bestLeft[p];
            }
            dpRight[i] = val;
        }

        // 3) อัปเดต bestLeft / bestRight
        bestLeft[i]  = max(bestLeft[i-1], dpLeft[i]);
        bestRight[i] = max(bestRight[i-1], dpRight[i]);
    }

    // คำตอบคือค่าที่มากที่สุดระหว่างฝั่งซ้าย / ขวา ทั้งหมด
    long long ans = max(bestLeft[n-1], bestRight[n-1]);

    cout << ans << "\n";
    return 0;
}
