#include<bits/stdc++.h>

using namespace std;
int main(){
    int n;
    double weight;
    cin >> weight >> n;
    double v[n+1],w[n+1];
    for(int i=1;i<=n;i++) cin >> v[i];
    for(int i=1;i<=n;i++) cin >> w[i];
    vector<tuple<double,double,double>> fractional(n+1);
    for(int i=1;i<=n;i++){
        fractional[i] = {(double)v[i]/w[i],v[i],w[i]};
    }
    sort(fractional.begin()+1,fractional.end());

    double curWeight = 0.0;
    double maxValue = 0.0;
    for(int i=n;i>=1;i--){
        double ratio = get<0>(fractional[i]);
        double value = get<1>(fractional[i]);
        double wi = get<2>(fractional[i]);
        if(curWeight+wi<= weight){
            curWeight+=wi;
            maxValue+=value;
        }else{
            double remain = weight-curWeight;
            maxValue+=ratio*remain;
            break;
        }
    }
    cout << fixed << setprecision(4) << maxValue << endl;
}