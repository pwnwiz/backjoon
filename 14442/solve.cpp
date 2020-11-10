// https://www.acmicpc.net/problem/14442
// 벽 부수고 이동하기 2
// Written in C++ langs
// 2020. 11. 10.
// Wizley

#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <tuple>

using namespace std;

int N, M, K;
char MAP[1001][1001];
int VISITED[1001][1001][11];

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
void bfs(){
    queue<tuple<int,int,int>> que;
    que.push({0,0,0});
    VISITED[0][0][0] = true;
    
    while(!que.empty()){
        int x = get<0>(que.front());
        int y = get<1>(que.front());
        int cnt = get<2>(que.front());
        que.pop();
        
        if(x == N-1 && y == M-1){
            cout << VISITED[x][y][cnt] << "\n";
            return;
        }
        
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx<0 || ny<0 || nx>=N || ny>=M) continue;
            if(VISITED[nx][ny][cnt]) continue;
            
            if(MAP[nx][ny] == '1'){
                if(cnt+1<=K && !VISITED[nx][ny][cnt+1]){
                    que.push({nx,ny,cnt+1});
                    VISITED[nx][ny][cnt+1] = VISITED[x][y][cnt]+1;
                }
            } else {
                if(!VISITED[nx][ny][cnt]){
                    que.push({nx,ny,cnt});
                    VISITED[nx][ny][cnt] = VISITED[x][y][cnt]+1;
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

    cin >> N >> M >> K;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> MAP[i][j];
        }
    }

    bfs();
    return 0;
}

