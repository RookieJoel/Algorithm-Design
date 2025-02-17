#include<bits/stdc++.h>

using namespace std;

vector<int> mod(const vector<int> &M,vector<int> &N,int k){
    vector<int> res(4);
    res[0] = (M[0]%k * N[0]%k + M[1]%k * N[2]%k)%k;
    res[1] = (M[0]%k * N[1]%k + M[1]%k * N[3]%k)%k;
    res[2] = (M[2]%k * N[0]%k + M[3]%k * N[2]%k)%k;
    res[3] = (M[2]%k * N[1]%k + M[3]%k * N[3]%k)%k;
    return res;
}

vector<int> solve(vector<int> &a, int n,int k){
    if(n==1)return a;
    if(n%2 == 0){
        vector<int> temp = solve(a,n/2,k);
        return mod(temp,temp,k);
    }else{
        vector<int> temp = solve(a,n/2,k);
        temp = mod(temp,temp,k);
        return mod(temp,a,k);
    }
}
int main(){
    int n,k;
    cin >> n >> k;
    vector<int> a(4);
    for(int i = 0; i < 4; i++){
        cin >> a[i];
    }
    vector<int> res = solve(a,n,k);
    cout << res[0] << " " << res[1]<< " " << res[2] << " " << res[3];

}