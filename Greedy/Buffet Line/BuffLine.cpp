#include<bits/stdc++.h>

using namespace std;

int main(){
    int f,w,n;
    cin >> f >> w >> n;
    vector<int> foodPosition(f);
    for(int i=0;i<f;i++) cin >> foodPosition[i];
    sort(foodPosition.begin(),foodPosition.end());
    vector<pair<int,int>> range(f);int i = 0;
    vector<int> visited(n+1);
    int place_light = min(foodPosition[0]+w,n);
    int st_cover = max(1,place_light-w);
    int end_cover = min(place_light+w,n);
    int count = 1;
    for(int i=1;i<f;i++){
        int start = max(1,foodPosition[i]-w);
        int end = min(foodPosition[i]+w,n);
        if(foodPosition[i] <= end_cover) continue;
        place_light = min(foodPosition[i]+w,n);
        st_cover = max(1,place_light-w);
        end_cover = min(place_light+w,n);
        count++;
    }

    cout << count;
}