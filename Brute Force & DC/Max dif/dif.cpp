/*** 
This is the question given to CS students of university of Toronto for mid-term

    Question 1. Divide-and-Conquer [20 marks]
    Write a divide-and-conquer algorithm that finds the maximum difference between any two elements
    of a given array of n numbers (not necessarily distinct) in O(n) time. For example, on input A =
    [4.5, 10, −2, π, −7.115], your algorithm should return 17.115.

    Note: For full marks, your answer must make use of the divide-and-conquer method. Partial marks will be
    given for an O(n log n) divide-and-conquer method. 

***/

#include<bits/stdc++.h>

using namespace std;

void solve(vector<double> &v,double &maxx,double &minn,int start,int stop){
    if(start == stop){
        minn = min(minn,v[start]);
        maxx = max(maxx,v[start]);
        return;
    }
    int mid = (start+stop)/2;
    solve(v,maxx,minn,start,mid);
    solve(v,maxx,minn,mid+1,stop);
}


int main(){
    int n;
    cin >> n;
    vector<double> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    double maxx = a[0],minn = a[0];
    solve(a,maxx,minn,0,n-1);
    cout << maxx - minn;
}