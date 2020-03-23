// https://www.acmicpc.net/problem/1261
// 알고스팟
// Written in C++ langs
// 2020. 03. 23.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#define INF 9999999

using namespace std;

int N, M;
int MAZE[101][101]={0,};
int DISTANCE[101][101]={0,};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void dijkstra(){
    queue<pair<int,int>> que;
    DISTANCE[1][1] = 0;
    que.push(make_pair(1,1));
    
    while(!que.empty()){
        int x = que.front().first;
        int y = que.front().second;
        que.pop();
        
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx<1 || ny<1 || nx>N || ny>M){
                continue;
            }
            
            int weight = MAZE[nx][ny] + DISTANCE[x][y];
            if(weight < DISTANCE[nx][ny]){
                DISTANCE[nx][ny] = weight;
                que.push(make_pair(nx, ny));
            }
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> M >> N;
    char input;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            cin >> input;
            MAZE[i][j] = input - '0';
        }
    }
    
    memset(DISTANCE, INF, sizeof(DISTANCE));
    
    dijkstra();
    cout << DISTANCE[N][M] << "\n";
    
    return 0;
    
}

