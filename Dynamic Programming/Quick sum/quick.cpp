#include<bits/stdc++.h>

using namespace std; 


int main(){
    int n,m,k;
    cin >> n >> m >> k;
    vector<vector<int>> a(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> a[i][j];
        }
    }
    vector<vector<int>> prefix(n,vector<int>(m));
    prefix[0][0] = a[0][0];
    for(int j=1;j<m;j++){
        prefix[0][j] = prefix[0][j-1] + a[0][j];
    }
    for(int i=1;i<n;i++){
        prefix[i][0] = prefix[i-1][0] + a[i][0];
        for(int j=1;j<m;j++){
            prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1] + a[i][j];
        }
    }

    cout << "PREFIX" <<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << prefix[i][j] << " ";
        }
        cout << endl;
    }


    while(k--){
        int r1,c1,r2,c2; 
        cin >> r1 >> c1 >> r2 >> c2; 
        if(r1-1 <0 && c1-1 >= 0) cout <<  prefix[r2][c2] - prefix[r2][c1-1] << endl;
        else if(c1-1 < 0 && r1-1>= 0) cout <<  prefix[r2][c2] - prefix[r1-1][c2] << endl;
        else if(c1-1 < 0 && r1-1 < 0) cout <<  prefix[r2][c2] <<endl;
        else cout << prefix[r2][c2] - prefix[r1-1][c2] - prefix[r2][c1-1] + prefix[r1-1][c1-1] << endl;
    }
}