#include<bits/stdc++.h>
using namespace std;

vector<int> dx = {-1,1,0,0};
vector<int> dy = {0,0,-1,1}; // L R U D

int main(){
    int r,c,k;
    cin >> r >> c >> k;

    vector<vector<int>> N(r+1,vector<int>(c+1));
    vector<vector<int>> S(r+1,vector<int>(c+1));
    vector<vector<bool>> visitedN(r+1,vector<bool>(c+1,false));
    vector<vector<bool>> visitedS(r+1,vector<bool>(c+1,false));
    set<pair<int,int>> worm;

    for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++)
            cin >> N[i][j];
    for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++)
            cin >> S[i][j];
    for(int i=0;i<k;i++){
        int x,y; cin >> x >> y;
        worm.insert({x,y});
    }

    queue<tuple<char,int,int>> q;
    q.push({'N',1,1});
    visitedN[1][1] = true;
    int count = 1;

    while(!q.empty()){
        auto [zone, r0, c0] = q.front(); q.pop();

        // warp
        if(zone == 'N' && worm.count({r0,c0}) && !visitedS[r0][c0] && S[r0][c0] == 0){
            visitedS[r0][c0] = true;
            q.push({'S', r0, c0});
            count++;
        }

        for(int d=0; d<4; d++){
            int nr = r0 + dx[d];
            int nc = c0 + dy[d];
            if(nr < 1 || nr > r || nc < 1 || nc > c) continue;

            if(zone == 'N' && N[nr][nc] == 0 && !visitedN[nr][nc]){
                visitedN[nr][nc] = true;
                q.push({'N', nr, nc});
                count++;
            } else if(zone == 'S' && S[nr][nc] == 0 && !visitedS[nr][nc]){
                visitedS[nr][nc] = true;
                q.push({'S', nr, nc});
                count++;
            }
        }
    }

    cout << count << endl;
}
