// https://www.acmicpc.net/problem/4963
// 섬의 개수
// Written in C++ langs
// 2020. 02. 24.
// Wizley

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;
int w=0, h=0;

int ARR[52][52]={0,};
int VISIT[52][52]={0,};
int ISLANDCOUNT=0;

void DFS(int x, int y){
    VISIT[x][y] = 1;
    if(x<0 || y<0 || x>h || y>w) return;
    
    if(ARR[x-1][y-1]==1 && !VISIT[x-1][y-1]) DFS(x-1, y-1);
    if(ARR[x-1][y]==1 && !VISIT[x-1][y]) DFS(x-1, y);
    if(ARR[x-1][y+1]==1 && !VISIT[x-1][y+1]) DFS(x-1, y+1);
    if(ARR[x][y-1] && !VISIT[x][y-1]) DFS(x, y-1);
    if(ARR[x][y+1] && !VISIT[x][y+1]) DFS(x, y+1);
    if(ARR[x+1][y-1]==1 && !VISIT[x+1][y-1]) DFS(x+1, y-1);
    if(ARR[x+1][y]==1 && !VISIT[x+1][y]) DFS(x+1, y);
    if(ARR[x+1][y+1]==1 && !VISIT[x+1][y+1]) DFS(x+1, y+1);
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(true){
        cin >> w >> h;
        if(w==0 && h==0)
            break;
        
        for(int i=1; i<=h; i++){
            for(int j=1; j<=w; j++){
                cin >> ARR[i][j];
            }
        }
        for(int i=1; i<=h; i++){
            for(int j=1; j<=w; j++){
                if(ARR[i][j]==1 && !VISIT[i][j]){
                    DFS(i, j);
                    ISLANDCOUNT++;
                }
            }
        }
        cout << ISLANDCOUNT << "\n";

        memset(ARR, 0, sizeof(ARR));
        memset(VISIT, 0, sizeof(VISIT));
        ISLANDCOUNT=0;
    }
  
    return 0;
    
}

