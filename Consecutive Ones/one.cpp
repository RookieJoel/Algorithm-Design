#include<bits/stdc++.h>

using namespace std;

void gen(int n,int k,vector<string> &ans,string cur,int maxCon,int curCon){
    if(cur.length() == n){
        if(maxCon >= k){
            ans.push_back(cur);   
        }
        return;
    }
    //case add 0
    gen(n,k,ans,cur+"0",maxCon,0);

    //case add 1
    gen(n,k,ans,cur+"1",max(maxCon,curCon+1),curCon+1);
}

int main(){
    int n,k;
    cin >> n >> k;
    vector<string> ans;
    string cur ="";
    gen(n,k,ans,cur,0,0);
    for(auto &x: ans) cout << x << endl;
    
}