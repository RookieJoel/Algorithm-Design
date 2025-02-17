#include<bits/stdc++.h>

using namespace std;

void gen(vector<string> &ans, string cur, int a,int b,int chosen){
    if(cur.length() == b){
        if(chosen == 0) ans.push_back(cur);
        return;
    }
    gen(ans,cur+"0",a,b,chosen);
    if(a > 0){
        gen(ans,cur+"1",a-1,b,chosen-1);
    }
    
}

int main(){
    int a,b;
    cin >> a >> b;
    vector<string> ans;
    string cur = "";
    gen(ans, cur,a,b,a);
    // sort(ans.begin(),ans.end());
    for(auto &x : ans) cout << x << endl;
}