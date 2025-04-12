#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> cnt(4, 0); // นับจำนวน 1, 2, 3

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    // สร้างตารางนับค่าที่ผิดตำแหน่ง
    vector<vector<int>> misplace(4, vector<int>(4, 0));

    // โซนของแต่ละตัวเลข
    int idx1 = 0;
    int idx2 = cnt[1];
    int idx3 = cnt[1] + cnt[2];

    for(int i = 0; i < cnt[1]; i++) misplace[1][a[i]]++;
    for(int i = cnt[1]; i < cnt[1]+cnt[2]; i++) misplace[2][a[i]]++;
    for(int i = cnt[1]+cnt[2]; i < n; i++) misplace[3][a[i]]++;

    int swaps = 0;
    
    // Swap ระหว่างโซนที่ผิด
    for(int i = 1; i <= 3; i++) {
        for(int j = i+1; j <= 3; j++) {
            int mn = min(misplace[i][j], misplace[j][i]);
            swaps += mn;
            misplace[i][j] -= mn;
            misplace[j][i] -= mn;
        }
    }

    // ที่เหลือคือสลับวงรอบ 3 ตัว เช่น 1->2->3->1 ต้องใช้ 2 swap ต่อหนึ่งรอบ
    int cycle = misplace[1][2] + misplace[1][3];
    swaps += 2 * cycle;

    cout << swaps << endl;
    return 0;
}
