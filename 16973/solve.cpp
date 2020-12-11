// https://www.acmicpc.net/problem/16973
// 직사각형 탈출
// Written in C++ langs
// 2020. 12. 11.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <map>
#include <set>
#include <queue>

using namespace std;

int N, M;
bool VISITED[1001][1001];
int MAP[1001][1001];

int A, B;
int SX, SY;
int EX, EY;

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

bool check(int x, int y, int direction){
    switch (direction) {
        case 0: // LEFT
            for(int nx=x; nx<x+A; nx++){
                if(MAP[nx][y] == 1) return false;
            }
            break;
        case 1: // RIGHT
            for(int nx=x; nx<x+A; nx++){
                if(MAP[nx][y+B-1] == 1) return false;
            }
            break;
        case 2: // UP
            for(int ny=y; ny<y+B; ny++){
                if(MAP[x][ny] == 1) return false;
            }
            break;
        case 3: // DOWN
            for(int ny=y; ny<y+B; ny++){
                if(MAP[x+A-1][ny] == 1) return false;
            }
            break;
    }
    return true;
}

void bfs(){
    queue<tuple<int,int,int>> que;
    que.push({SX-1, SY-1,0});
    VISITED[SX-1][SY-1] = true;
    
    while(!que.empty()){
        int x = get<0>(que.front());
        int y = get<1>(que.front());
        int cnt = get<2>(que.front());
        que.pop();
        
        if(x == EX-1 && y == EY-1){
            cout << cnt << "\n";
            return;
        }
        
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx<0 || ny<0 || nx+A-1>=N || ny+B-1>=M) continue;
            if(VISITED[nx][ny]) continue;
            
            if(check(nx,ny,i)){
                que.push({nx,ny,cnt+1});
                VISITED[nx][ny] = true;
            }
        }
    }
    
    cout << "-1\n";
    return;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> MAP[i][j];
        }
    }
    
    cin >> A >> B >> SX >> SY >> EX >> EY;
    
    bfs();
    
    return 0;
    
}

