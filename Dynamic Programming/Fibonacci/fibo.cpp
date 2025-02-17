#include<bits/stdc++.h>

using namespace std ;
map<int,int> mem; 
int fibo(int n){
    if(n == 0) return 0;
    if(n == 1) return 1;
    return fibo(n-1) + fibo(n-2);
}


int fibo_TD(int n){
    if(n == 0 || n == 1) return n ;
    if(n>=2){
    if(mem[n] > 0) return mem[n];
    int val = fibo_TD(n-1) + fibo_TD(n-2);
    mem[n] =val;
    return val;
    }
}

int fibo_BU(int n){
    vector<int> v(n);
    v[0] = 0;
    v[1] = 1;
    for(int i =2;i<=n;i++){
        v[i] = v[i-1] + v[i-2];
    }
    return v[n];
}

int main(){
    int n; 
    cin >> n;
    cout << fibo_BU(n); 
}