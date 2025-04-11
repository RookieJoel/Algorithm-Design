#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,l;
    cin >> n >>l;
    vector<int> p(n);
    for(int i=0;i<n;i++) cin >> p[i];
    sort(p.begin(),p.end());
    int st_cover = p[0];
    int en_cover = p[0]+l;
    int count = 1;
    for(int i=1;i<n;i++){
        int start = p[i];
        int end = p[i]+l;
        if(p[i] < en_cover) continue;
        st_cover = p[i];
        en_cover = p[i]+l;
        count++;
    }
    cout << count;
}