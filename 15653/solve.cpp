// https://www.acmicpc.net/problem/15653
// 구슬 탈출 4
// Written in C++ langs
// 2020. 11. 09.
// Wizley

#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <tuple>

using namespace std;

int N, M;

pair<int,int> HOLE;
pair<int,int> RED;
pair<int,int> BLUE;
bool VISITED[11][11][11][11];
char MAP[11][11];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

void positioning(int &x, int &y, int &move, int side){
    while(MAP[x+dx[side]][y+dy[side]] != '#'){
        if(MAP[x][y] == 'O') break;
        x += dx[side];
        y += dy[side];
        move++;
    }
}

void alignIfSamePosition(int &rx, int &ry, int &bx, int &by, int &rmv, int &bmv, int side){
    if(rx == bx && by == ry){
        if(rmv > bmv){
            rx -= dx[side];
            ry -= dy[side];
        } else {
            bx -= dx[side];
            by -= dy[side];
        }
    }
}

void bfs(){
    queue<tuple<pair<int,int>, pair<int,int>, int>> que;
    VISITED[RED.first][RED.second][BLUE.first][BLUE.second] = true;
    que.push({RED, BLUE, 0});
    
    while(!que.empty()){
        pair<int,int> new_RED = get<0>(que.front());
        pair<int,int> new_BLUE = get<1>(que.front());
        int cnt = get<2>(que.front());
        que.pop();
        
        for(int i=0; i<4; i++){
            int rx = new_RED.first;
            int ry = new_RED.second;
            int bx = new_BLUE.first;
            int by = new_BLUE.second;
            
            int rmv = 0;
            int bmv = 0;
            
            positioning(rx, ry, rmv, i);
            positioning(bx, by, bmv, i);
            
            if(MAP[bx][by] == 'O') continue;
            if(MAP[rx][ry] == 'O'){
                cout << cnt+1 << "\n";
                return;
            }
            
            alignIfSamePosition(rx, ry, bx, by, rmv, bmv, i);
            
            if(!VISITED[rx][ry][bx][by]){
                VISITED[rx][ry][bx][by] = true;
                que.push({make_pair(rx,ry),make_pair(bx,by),cnt+1});
            }
        }
    }
    cout << "-1\n";
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> MAP[i][j];
            if(MAP[i][j] == 'R') RED = {i,j};
            if(MAP[i][j] == 'B') BLUE = {i,j};
            if(MAP[i][j] == 'O') HOLE = {i,j};
        }
    }
    
    bfs();
    
    return 0;
}

