#include<bits/stdc++.h>

using namespace std;

int binarySearch(vector<int> &v, int start, int stop,int target,int ans){
    if(start > stop) return ans;
    int mid = (start+stop)/2; 
    
    if(v[mid] <= target){
        ans = mid;
        return binarySearch(v,mid+1,stop,target,ans);
    }

    return binarySearch(v,start,mid-1,target,ans);
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i =0;i<m;i++){
        int x;
        cin >> x;
        int ans = binarySearch(a,0,n-1,x,-1);
        cout << ans << endl;
    }
}