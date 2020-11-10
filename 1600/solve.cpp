// https://www.acmicpc.net/problem/1600
// 말이 되고픈 원숭이
// Written in C++ langs
// 2020. 11. 10.
// Wizley

#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <tuple>

using namespace std;

int K;
int VISITED[201][201][31];
int MAP[201][201];
int N, M;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

int horseX[] = {-2,-2,-1,-1,1,1,2,2};
int horseY[] = {-1,1,-2,2,-2,2,-1,1};
void bfs(){
    queue<tuple<int,int,int,int>> que;
    que.push({0,0,0,0});
    VISITED[0][0][0] = 0;
    
    while(!que.empty()){
        int x = get<0>(que.front());
        int y = get<1>(que.front());
        int d = get<2>(que.front());
        int k = get<3>(que.front());
        que.pop();
        
        if(x== N-1 && y== M-1){
            cout << d << "\n";
            return;
        }
        
        if(VISITED[x][y][k]<d) continue;
        
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx<0 || ny<0 || nx>=N || ny>=M) continue;
            if(MAP[nx][ny] == 1) continue;
            
            if(!VISITED[nx][ny][k]){
                VISITED[nx][ny][k] = d+1;
                que.push({nx,ny,d+1,k});
            }
            
            else if(VISITED[nx][ny][k]>d+1){
                VISITED[nx][ny][k] = d+1;
                que.push({nx,ny,d+1,k});
            }
            
        }
        
        if(k<K){
            for(int i=0; i<8; i++){
                int nx = x + horseX[i];
                int ny = y + horseY[i];
                
                if(nx<0 || ny<0 || nx>=N || ny>=M) continue;
                if(MAP[nx][ny] == 1) continue;
                
                if(!VISITED[nx][ny][k+1]){
                    VISITED[nx][ny][k+1] = d+1;
                    que.push({nx,ny,d+1,k+1});
                }
                
                else if(VISITED[nx][ny][k+1]>d+1){
                    VISITED[nx][ny][k+1] = d+1;
                    que.push({nx,ny,d+1,k});
                }
            }
        }
    }
    
    cout << "-1\n";
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> K >> M >> N;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> MAP[i][j];
        }
    }
    
    bfs();
    
    return 0;
}

