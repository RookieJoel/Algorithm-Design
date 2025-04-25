#include <bits/stdc++.h>
using namespace std;

int N, K;
vector<int> c;
vector<int> bad,choose;
int best = INT_MIN;

bool check(const vector<int>& decisions) {
    int n = decisions.size();
    for(int i = 0; i + K <= n; ++i) {
        bool match = true;
        for(int j = 0; j < K; ++j) {
            if (decisions[i + j] != bad[j]) {
                match = false;
                break;
            }
        }
        if (match) {
            return false;
        }
    }
    return true;
}
void solve(int idx,int total,int lastChose,vector<int> &choose){
    if(idx == N){
        if(check(choose)){
            best = max(best,total);
        }
        return;
    }
    if(choose.size() > K && !check(choose)) return;
    //take
    if(idx > lastChose+1){
        choose.push_back(idx);
        solve(idx+1,total+c[idx],idx,choose);
        choose.pop_back();
    }
    //skip
    solve(idx+1,total,lastChose,choose);
}
int main() {
    cin >> N >> K;
    c.resize(N);
    bad.resize(K);
    for (int i = 0; i < N; ++i) cin >> c[i];
    for (int i = 0; i < K; ++i)cin >> bad[i];
    vector<int> choose;
    solve(0,0,-1,choose);
    cout << best;
}
