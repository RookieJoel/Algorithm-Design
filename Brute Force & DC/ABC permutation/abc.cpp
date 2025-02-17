#include <bits/stdc++.h>
using namespace std;

void generate_permutations(string current, int A, int B, int C, vector<string> &ans,int n) {
    if(current.length() == n){
        ans.push_back(current);
        return;
    }
    if(A > 0){
        generate_permutations(current+"A",A-1,B,C,ans,n);
    }
    if(B > 0){
        generate_permutations(current+"B",A,B-1,C,ans,n);
    }
    if(C > 0){
        generate_permutations(current+"C",A,B,C-1,ans,n);
    }
}

int main() {
    int n, i, j, k;
    cin >> n >> i >> j >> k;
    if(i+j+k < n){
        cout << 0;
    }
    else{
    vector<string> results;
    string current = "";

    generate_permutations(current, i, j, k, results,n);

    cout << results.size() << endl;

    for (const auto &perm : results) {
        cout << perm << endl;
    }
    }

}
