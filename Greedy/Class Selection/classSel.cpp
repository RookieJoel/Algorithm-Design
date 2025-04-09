#include<bits/stdc++.h>

using namespace std;

struct Selection {
    int start;
    int end;
};

bool comp(const Selection &a, const Selection &b) {
    return a.end < b.end;
}


int main(){
    int n;
    cin >> n;
    vector<Selection> sel(n+1);
    for(int i=1;i<=n;i++) cin >> sel[i].start;
    for(int i=1;i<=n;i++) cin >> sel[i].end;
    sort(sel.begin()+1,sel.end(),comp);

    int ans = 1;
    int e = sel[1].end;
    for(int i=2;i<=n;i++){
        int st = sel[i].start;
        int en = sel[i].end;
        if(e <= st){
            e = en;
            ans++;
        }
    }
    cout << ans;
}