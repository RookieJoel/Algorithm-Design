#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<long long> a(n);
    for(int i=0; i<n; i++) cin >> a[i];

    ll curSum = a[0];
    ll maxSum = a[0];
    vector<int> prefix(n);
    prefix[0] = a[0];
    for(int i=1;i<n;i++){
        curSum = max(a[i],curSum+a[i]);
        maxSum = max(maxSum,curSum);
        prefix[i] = maxSum;
    }

    curSum = a[n-1];
    maxSum = a[n-1];
    vector<int> suffix(n);
    suffix[n-1] = a[n-1];
    int k = 0;
    for(int i=n-2;i>=0;i--){
        curSum = max(a[i],curSum+a[i]);
        maxSum = max(maxSum,curSum);
        suffix[i] = maxSum;
    }

    ll max2 = a[0];
    for(int i = 0; i < n-1; i++){
        ll sum = prefix[i] + suffix[i+1];
        if(sum > max2){
            max2 = sum;
        }
    }
    cout << "prefix "<<endl;
    for(auto &x : prefix) cout << x << " ";
    cout << "\nsuffix "<<endl;
    for(auto &x : suffix) cout << x << " ";
    cout <<endl;
    ll max1 = prefix[n-1];
    cout << max(max2,max1);
}
