// https://www.acmicpc.net/problem/16959
// 체스판 여행 1
// Written in C++ langs
// 2020. 12. 09.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <map>
#include <set>
#include <queue>

using namespace std;

int MAP[11][11];
int VISITED[11][11][101][3];
pair<int,int> START;
int TOTAL = 987654321;
int N;

enum {
    KNIGHT = 0,
    BISHOP = 1,
    LOOK = 2
};

int kx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int ky[] = {-1, 1, -2, 2, -2, 2, -1, 1};

int bx[] = {-1, -1, 1, 1};
int by[] = {-1, 1, -1, 1};

int lx[] = {0,0,-1,1};
int ly[] = {-1,1,0,0};

void bfs(){
    queue<tuple<int,int,int,int>> que;
    que.push({1, START.first, START.second, KNIGHT});
    que.push({1, START.first, START.second, BISHOP});
    que.push({1, START.first, START.second, LOOK});
    VISITED[START.first][START.second][1][KNIGHT] = 0;
    VISITED[START.first][START.second][1][BISHOP] = 0;
    VISITED[START.first][START.second][1][LOOK] = 0;
        
    while(!que.empty()){
        int no = get<0>(que.front());
        int x = get<1>(que.front());
        int y = get<2>(que.front());
        int type = get<3>(que.front());
        que.pop();
        
        if(no == N*N){
            TOTAL = min(TOTAL, VISITED[x][y][no][type]);
        }
        
        if(no > N*N) continue;
        
        switch(type){
            case KNIGHT:
                for(int i=0; i<8; i++){
                    int nx = x + kx[i];
                    int ny = y + ky[i];

                    if(nx<0 || ny<0 || nx>=N || ny>=N) continue;
                    
                    int target = no;
                    if(MAP[nx][ny] == no+1) target += 1;
                    if(VISITED[nx][ny][target][type] != -1) continue;

                    VISITED[nx][ny][target][type] = VISITED[x][y][no][type] + 1;
                    que.push({target, nx, ny, type});
                }
                break;
            case BISHOP:
                for(int i=0; i<4; i++){
                    int c = 0;
                    
                    while(true){
                        c++;
                        int nx = x + bx[i] * c;
                        int ny = y + by[i] * c;
   
                        if(nx<0 || ny<0 || nx>=N || ny>=N) break;
                        
                        int target = no;
                        if(MAP[nx][ny] == no+1) target += 1;
                        if(VISITED[nx][ny][target][type] != -1) continue;

                        VISITED[nx][ny][target][type] = VISITED[x][y][no][type] + 1;
                        que.push({target, nx, ny, type});
                    }
                }
                break;
            case LOOK:
                for(int i=0; i<4; i++){
                    int c = 0;
                    
                    while(true){
                        c++;
                        int nx = x + lx[i] * c;
                        int ny = y + ly[i] * c;
   
                        if(nx<0 || ny<0 || nx>=N || ny>=N) break;
                        
                        int target = no;
                        if(MAP[nx][ny] == no+1) target += 1;
                        if(VISITED[nx][ny][target][type] != -1) continue;

                        VISITED[nx][ny][target][type] = VISITED[x][y][no][type] + 1;
                        que.push({target, nx, ny, type});
                    }
                }
                break;
        }

        for(int next_type=0; next_type<3; next_type++){
            if(type == next_type) continue;
            if(VISITED[x][y][no][next_type] != -1) continue;
         
            VISITED[x][y][no][next_type] = VISITED[x][y][no][type] + 1;
            que.push({no,x,y,next_type});
        }
    }
    
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    memset(VISITED, -1, sizeof(VISITED));
    
    cin >> N;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> MAP[i][j];
            if(MAP[i][j] == 1) START = {i,j};
        }
    }
    bfs();

    cout << TOTAL << "\n";
    
    return 0;
}

