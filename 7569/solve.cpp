// https://www.acmicpc.net/problem/7569
// 토마토
// Written in C++ langs
// 2020. 04. 10.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <queue>
#include <tuple>

using namespace std;

int ARR[100][100][100];
bool VISITED[100][100][100];
queue<tuple<int,int,int>> QUE;
int M, N, H;
int DAY = 0;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

void bfs(){
    while(!QUE.empty()){
        queue<tuple<int,int,int>> que2;
        
        while(!QUE.empty()){
            
            int h = get<0>(QUE.front());
            int x = get<1>(QUE.front());
            int y = get<2>(QUE.front());
            QUE.pop();
            
            for(int i=0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
            
            
                if(nx<0 || ny<0 || nx>=N || ny>=M) continue;
                    
                if(ARR[h][nx][ny] == 0 && !VISITED[h][nx][ny]){
                    ARR[h][nx][ny] = 1;
                    VISITED[h][nx][ny] = true;
                    que2.push({h,nx,ny});
                }
            }
            
            int up = h-1;
            int down = h+1;
            if(up>=0 && up<H){
                if(ARR[up][x][y] == 0 && !VISITED[up][x][y]){
                    ARR[up][x][y] = 1;
                    VISITED[up][x][y] = true;
                    que2.push({up,x,y});
                }
            }
            
            if(down>=0 && down<H){
                if(ARR[down][x][y] == 0 && !VISITED[down][x][y]){
                    ARR[down][x][y] = 1;
                    VISITED[down][x][y] = true;
                    que2.push({down,x,y});
                }
            }
        }
        QUE = que2;
        DAY++;
    }
    
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N >> H;
    
    for(int i=0; i<H; i++){
        for(int j=0; j<N; j++){
            for(int k=0; k<M; k++){
                cin >> ARR[i][j][k];
                if(ARR[i][j][k] == 1){
                    QUE.push({i,j,k});
                    VISITED[i][j][k] = true;
                }
            }
        }
    }
    
    bfs();
    
    for(int i=0; i<H; i++){
        for(int j=0; j<N; j++){
            for(int k=0; k<M; k++){
                if(ARR[i][j][k] == 0){
                    cout << "-1\n";
                    exit(0);
                }
            }
        }
    }
    
    (DAY == 0) ? cout << "0\n" : cout << DAY-1 << "\n";
    
    return 0;
    
}

