#include <bits/stdc++.h>
using namespace std;

const int MAXN = 505;

int K, N;
double R[MAXN][MAXN];
double W[MAXN][MAXN];

int main() {
    cin >> K;
    for (int t = 0; t < K; t++) {
        cin >> N;

        // รับค่าอัตราแลกเปลี่ยน
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                cin >> R[i][j];

        // แปลง R เป็น W โดยใช้ -log(R)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                W[i][j] = -log(R[i][j]);

        // Floyd-Warshall
        for (int k = 0; k < N; k++)
            for (int i = 0; i < N; i++)
                for (int j = 0; j < N; j++)
                    W[i][j] = min(W[i][j], W[i][k] + W[k][j]);

        // เช็คว่ามี cycle ที่ทำให้ W[i][i] < 0 หรือไม่
        bool arbitrage = false;
        for (int i = 0; i < N; i++) {
            if (W[i][i] < 0.0) {
                arbitrage = true;
                break;
            }
        }

        cout << (arbitrage ? "YES" : "NO") << '\n';
    }
    return 0;
}
