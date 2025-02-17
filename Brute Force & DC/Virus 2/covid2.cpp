#include<bits/stdc++.h>

using namespace std;

bool check(vector<int> &v){
    int a=0,b=0;
    int mid = v.size() >> 1;
    for(int i=0;i<mid;i++){
        if(v[i]==1) a++;
    }
    for(int i=mid;i<v.size();i++){
        if(v[i]==1) b++;
    }
    return abs(a-b) <= 1;
}

bool isVirus(vector<int> &v,int len){
    if(len == 2){
        return (v[0] == 0 && v[1] == 0) || (v[0] == 0 && v[1] == 1) || (v[0] == 1 && v[1] == 0) || (v[0] == 1 && v[1] == 1);
    }
    int mid = len >> 1;
    vector<int> left(mid),right(mid);
    for(int i=0;i<mid;i++){
        left[i] = v[i];
        right[i] = v[i+mid];
    }
    bool leftVirus = isVirus(left,mid);
    bool rightVirus = isVirus(right,mid);
    return leftVirus && rightVirus && check(v);
}
int main(){
    int n,k;
    cin >> n >> k;
    int len = pow(2, k);
    while(n--){
        vector<int> v(len); 
        for(int i = 0; i < len; i++){
            cin >> v[i];
        }
        isVirus(v,len) ? cout << "yes\n" : cout << "no\n";
    }
}