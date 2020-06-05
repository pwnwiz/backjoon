// https://www.acmicpc.net/problem/1520
// 내리막 길
// Written in C++ langs
// 2020. 06. 05.
// Wizley

#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int N, M;
int MAP[501][501];
int DP[501][501];

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

int dfs(int x, int y){
    
    // 해당 경로에 이미 도달하여 경우의 수를 가지고 있는 경우
    if(DP[x][y] != -1){
        return DP[x][y];
    }
    
    // 초기값이 -1이기 때문에 더하기 전에 0으로 초기화 해주어야됨
    DP[x][y] = 0;
    
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx<0 || ny<0 || nx>=N || ny>=M) continue;
        
        if(MAP[nx][ny] < MAP[x][y]){
            DP[x][y] += dfs(nx,ny);
        }
    }
    return DP[x][y];
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> MAP[i][j];
            DP[i][j] = -1;
        }
    }
    
    // 도착지를 기준점으로 1로 잡음
    // 만약 어떤 경로가 도착지가 도달하면 그 길은 해당 위치로부터 도착지를 갈 수 있는 경우의 수를 나타냄
    DP[N-1][M-1]=1;
    
    dfs(0,0);
    
    DP[0][0]<0 ? cout << "0\n" : cout << DP[0][0] << "\n";
    return 0;
    
}

