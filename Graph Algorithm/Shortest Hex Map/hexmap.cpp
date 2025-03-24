#include<bits/stdc++.h>

using namespace std;
int dx[] = {0,1,1,0,-1,-1};
int dyOdd[] = {-1,0,1,1,1,0};
int dyEven[] = {-1,-1,0,1,0,-1};

int main(){
    int r,c;
    cin >> r >> c;
    int a1,b1,a2,b2;
    cin >> a1>>b1>>a2>>b2;
    vector<vector<int>> hex(r+1,vector<int>(c+1));
    for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++)
            cin >> hex[i][j];
    vector<vector<int>> dist(r+1,vector<int>(c+1,INT_MAX)); //dist[r][c] = weight <r,c> = 0

    set<tuple<int,int,int>> s;
    s.insert({hex[a1][b1],a1,b1});
    dist[a1][b1] = hex[a1][b1];
    while(!s.empty()){
        auto it = *s.begin();
        int w = get<0>(it);
        int row = get<1>(it);
        int col = get<2>(it);
        s.erase(it);
        for(int i=0;i<6;i++){
            int nr = row + dx[i];
            int nc;
            if(row%2==0) nc = col+dyEven[i];
            else nc = col+dyOdd[i];
            if(nr>=1 && nr <= r && nc >=1 && nc <= c){
                // cout << "nr: " << nr << " nc: " << nc << " dist: " << dist[nr][nc] << " cost:" <<w + hex[nr][nc] <<endl;
                if(dist[nr][nc] > w + hex[nr][nc]){
                    s.erase({dist[nr][nc],nr,nc});
                    dist[nr][nc] = w + hex[nr][nc];
                    if(nr == a2 && nc == b2){
                        cout << dist[nr][nc];
                        return 0;
                    }
                    s.insert({dist[nr][nc],nr,nc});
                }
            }
        }
    }

    // for(int i=1;i<=r;i++){
    //     for(int j=1;j<=c;j++){
    //         cout << dist[i][j] << " ";
    //     }cout << endl;
    // }

}