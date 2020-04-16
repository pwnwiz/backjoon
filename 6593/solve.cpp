// https://www.acmicpc.net/problem/6593
// 상범 빌딩
// Written in C++ langs
// 2020. 04. 16.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
#include <tuple>

using namespace std;

int X, Y, Z;

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

char BUILDING[30][30][30]={0,};
bool VISITED[30][30][30]={0,};
tuple<int,int,int> START;

void bfs(){
    queue<tuple<int,int,int>> que;
    int cnt = 0;
    que.push(START);
        
    while(!que.empty()){
        cnt++;
        queue<tuple<int,int,int>> que2;
        
        while(!que.empty()){
            int z = get<0>(que.front());
            int x = get<1>(que.front());
            int y = get<2>(que.front());
            int up = z+1;
            int down = z-1;
            que.pop();
            
            if(BUILDING[z][x][y] == 'E'){
                cout << "Escaped in " << cnt-1 << " minute(s)." << "\n";
                return;
            }
            
            for(int i=0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(nx<0 || ny<0 || nx>=X || ny>=Y) continue;
                
                if(BUILDING[z][nx][ny]!='#' && !VISITED[z][nx][ny]){
                    VISITED[z][nx][ny] = true;
                    que2.push({z,nx,ny});
                }
            }
            
            if(up<Z && BUILDING[up][x][y]!='#' && !VISITED[up][x][y]){
                VISITED[up][x][y] = true;
                que2.push({up,x,y});
            }
            
            if(down>=0 && BUILDING[down][x][y]!='#' && !VISITED[down][x][y]){
                VISITED[down][x][y] = true;
                que2.push({down,x,y});
            }
        }
        que = que2;
    }
    
    cout << "Trapped!\n";
    
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    while(true){
        cin >> Z >> X >> Y;
        if(Z==0 && X==0 && Y==0) break;
        
        for(int i=0; i<Z; i++){
            for(int x=0; x<X; x++){
                for(int y=0; y<Y; y++){
                    cin >> BUILDING[i][x][y];
                    if(BUILDING[i][x][y]=='S'){
                        VISITED[i][x][y] = true;
                        START={i,x,y};
                    }
                }
            }
        }
        
        bfs();
        
        memset(VISITED, false, sizeof(VISITED));
        
    }
    
}

