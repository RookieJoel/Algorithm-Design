#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<pair<long long,long long>> v(n);
    for(int i =0;i<n;i++){
        long long a,b;
        cin >> a >> b;
        v[i] = {a,b};
    }
    sort(v.begin(),v.end());
    long long start = v[0].first;
    long long end = v[0].second;

    vector<pair<long long,long long>> merge;
    for(int i =1;i<v.size();i++){
        if(v[i].first <= end || v[i].first == end+1){
            end = max(end,v[i].second);
        }else{
            merge.push_back({start,end});
            start = v[i].first;
            end = v[i].second;
        }
    }
    merge.push_back({start,end});
    for(auto &i:merge){
        cout << i.first << " " << i.second << " ";
    }

}