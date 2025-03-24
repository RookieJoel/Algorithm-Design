#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> start(k); // จุดเริ่มต้นของไวรัส
    for (int &s : start) cin >> s;

    vector<int> c(n); // เวลาที่ใช้ในการเจาะแต่ละ server
    for (int &x : c) cin >> x;

    vector<vector<int>> graph(n); // กราฟแบบไม่ถ่วงน้ำหนัก (สายเคเบิล)
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    // Dijkstra's Algorithm
    vector<int> hacked_time(n, INF); // เวลาที่ถูกเจาะสำเร็จ
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    for (int s : start) {
        hacked_time[s] = c[s];
        pq.push({hacked_time[s], s});
    }

    while (!pq.empty()) {
        auto [t, u] = pq.top(); pq.pop();

        if (t > hacked_time[u]) continue; // ข้ามถ้าเคยมาเร็วกว่านี้

        for (int v : graph[u]) {
            int next_time = t + c[v];
            if (next_time < hacked_time[v]) {
                hacked_time[v] = next_time;
                pq.push({next_time, v});
            }
        }
    }

    for(auto &x : hacked_time)cout << x << " ";

    // หาค่าเวลาสูงสุดที่เครื่องสุดท้ายถูกเจาะ
    int result = *max_element(hacked_time.begin(), hacked_time.end());
    cout << result << '\n';

    return 0;
}
