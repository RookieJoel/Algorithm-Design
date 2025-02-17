#include<bits/stdc++.h>

using namespace std;


// int bino(int n,int k){
//     if(n==k || k ==0)return 1;
//     return bino(n-1,k-1) + bino(n-1,k);
// }

int bino_TD(int n, int k, vector<vector<int>> &mem) { 
    if (k == 0 || n == k) return 1;
    if (mem[n][k] != -1) return mem[n][k];

    int res = bino_TD(n-1, k-1, mem) + bino_TD(n-1, k, mem); 
    mem[n][k] = res; 

    return res;
}

int bino_BU(int n,int k){
    vector<vector<int>> table(n+1,vector<int>(n+1));
    for(int i=0;i<n+1;i++){
        for(int j=0;j<n+1;j++){
            if(j == 0 || j == i) table[i][j] = 1;
        }
    }
    

    for(int i=2;i<n+1;i++){
        for(int j=1;j<i;j++){
            table[i][j] = table[i-1][j-1] + table[i-1][j];
        }
    }

    return table[n][k];
}
int main() {
    int n, k;
    cin >> n >> k;
    
    vector<vector<int>> mem(n + 1, vector<int>(k + 1, -1)); 

    cout << bino_BU(n, k) << endl;
}
