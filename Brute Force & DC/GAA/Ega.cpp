#include<bits/stdc++.h>

using namespace std;

int len_gk(int k){
    if(k == 0) return 3;
    return len_gk(k-1) + (k+3) + len_gk(k-1);
}

char solve(int targetIndex,int k,int start,int stop){
    if(k==0){
        if(targetIndex == start) return 'g';
        return 'a';
    }
    if((start <= targetIndex && targetIndex <= len_gk(k-1)+start-1)){
        return solve(targetIndex,k-1,start,len_gk(k-1)+start-1);
    }else if((len_gk(k-1)+k+3+start <= targetIndex && targetIndex <= len_gk(k-1)+k+3+start+len_gk(k-1)-1)){
        return solve(targetIndex,k-1,len_gk(k-1)+k+3+start,len_gk(k-1)+k+3+start+len_gk(k-1)-1);
    }else{
        if(targetIndex == len_gk(k-1)+start ) return 'g';
        return 'a';
    }

}

int main(){
    int target;
    cin >> target;

    int size=3,temp=3,i=1;
    while(size < target){
        size = 2*temp +(i+3);
        temp = size;
        if(size>=target)break;
        i++;
    }
    cout << solve(target,i,1,len_gk(i));
   

}