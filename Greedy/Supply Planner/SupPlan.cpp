#include<bits/stdc++.h>

using namespace std;

struct procedure {
    int day,action,label;
};
bool comp(const procedure &a, const procedure &b) {
    return a.day < b.day ;
}

int main(){
    int n,m,k;
    cin >>n>>m>>k;
    vector<procedure> p(k);
    for(int i=0;i<k;i++){
        int d,e,l;
        cin >> d>>e>>l;
        //d = day e:0 = A e:1 = B l=label
        p[i].day = d;
        p[i].action = e;
        p[i].label = l;
    }
    sort(p.begin(),p.end(),comp);
    queue<int> done,req;
    for(int i=0;i<k;i++){
        int act = p[i].action;
        int num = p[i].label;
        if(act == 1){ //req
            if(done.empty()){
                cout << 0 <<endl;
                req.push(num);
            }else{
                cout << done.front()<<endl;
                done.pop();
            }
        }else if(act == 0){ //produce
            if(req.empty()){
                cout << 0 <<endl;
                done.push(num);
            }else{
                cout << req.front() << endl;
                req.pop();
            }
        }
    } 
}