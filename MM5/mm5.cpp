#include<bits/stdc++.h>

using namespace std;

int median(vector<int> &v,int n){
    sort(v.begin(),v.end());
    return v[n/2];
}

int mm5(vector<int> &v,int n){
    if(n <= 5){
        return median(v,n);
    }
    vector<int> medians;
    for(int i = 0; i < n; i+=5){
        vector<int> temp;
        for(int j = i; j < i+5 && j < n; j++){
            temp.push_back(v[j]);
        }
        medians.push_back(median(temp,temp.size()));
    }
    return mm5(medians,medians.size());
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << mm5(a,n);
}