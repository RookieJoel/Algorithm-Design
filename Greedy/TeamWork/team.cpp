#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> time(m);
    for(int i = 0; i < m; i++) cin >> time[i];
    
    sort(time.begin(), time.end());

    long long total = 0; 
    for(int i = 0; i < n; i++){ 
        int sum = 0;
        for(int j = i; j < m; j += n){
            sum += time[j];
            total += sum;
        }
    }

    cout << fixed << setprecision(3) << (double)total / m << endl;
}
