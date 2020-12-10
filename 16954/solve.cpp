// https://www.acmicpc.net/problem/16954
// 움직이는 미로 탈출
// Written in C++ langs
// 2020. 12. 10.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <map>
#include <set>
#include <queue>

using namespace std;

char MAP[8][8];
bool VISITED[8][8][10];

int dx[] = {0,0,-1,1,-1,-1,1,1,0};
int dy[] = {-1,1,0,0,1,-1,1,-1,0};

int bfs(){
    queue<tuple<int,int,int>> que;
    que.push({7,0,0});
    VISITED[7][0][0] = true;
    
    while(!que.empty()){
        int x = get<0>(que.front());
        int y = get<1>(que.front());
        int t = get<2>(que.front());
        que.pop();
        
        if(x == 0 && y == 7) return 1;
        
        for(int i=0; i<9; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx<0 || ny<0 || nx>=8 || ny>=8) continue;
            if(nx-t>=0 && MAP[nx-t][ny] == '#') continue;
            if(nx-t-1>=0 && MAP[nx-t-1][ny] == '#') continue;
            
            int nt = min(t+1, 8);
            if(VISITED[nx][ny][nt]) continue;
            
            que.push({nx,ny,nt});
            VISITED[nx][ny][nt] = true;
        }
        
    }
    
    return 0;
    
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            cin >> MAP[i][j];
        }
    }
    
    bool result = bfs();
    cout << result << "\n";
    
    return 0;
    
}

