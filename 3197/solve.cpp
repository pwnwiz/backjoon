// https://www.acmicpc.net/problem/3197
// 백조의 호수
// Written in C++ langs
// 2020. 11. 13.
// Wizley

#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <tuple>
#include <stack>

using namespace std;

bool VISITED[1501][1501];
bool CHECK[1501][1501];
char MAP[1501][1501];
int R, C;

int CNT = 0;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

queue<pair<int,int>> WATER;
vector<pair<int,int>> L;

void bfs(){
    queue<pair<int,int>> que;
    que.push(L[0]);
    VISITED[L[0].first][L[0].second] = true;
    while(true){
        // One of Swan into Queue
        queue<pair<int,int>> que2;
        while(!que.empty()){
            int x = que.front().first;
            int y = que.front().second;
            que.pop();
            
            for(int i=0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(nx<0 || ny<0 || nx>=R || ny>=C) continue;
                if(VISITED[nx][ny]) continue;
                
                switch(MAP[nx][ny]){
                    case '.':
                        VISITED[nx][ny] = true;
                        que.push({nx,ny});
                        break;
                    case 'L':
                        VISITED[nx][ny] = true;
                        return;
                        break;
                    case 'X':
                        VISITED[nx][ny] = true;
                        que2.push({nx,ny});
                        break;
                }
            }
        }
        que = que2;
        
        // No Swan Meets
        CNT++;
        
        queue<pair<int,int>> water2;
        while(!WATER.empty()){
            int x = WATER.front().first;
            int y = WATER.front().second;
            WATER.pop();
            
            for(int i=0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(nx<0 || ny<0 || nx>=R || ny>=C) continue;
                if(VISITED[nx][ny] || MAP[nx][ny]!='X') continue;
                
                MAP[nx][ny] = '.';
                water2.push({nx,ny});
            }
        }
        WATER = water2;
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C;
    for(int r=0; r<R; r++){
        for(int c=0; c<C; c++){
            cin >> MAP[r][c];
            if(MAP[r][c] == 'L') L.push_back({r,c});
            if(MAP[r][c] != 'X') WATER.push({r,c});
        }
    }

    bfs();
    cout << CNT << "\n";
   
    return 0;
}

