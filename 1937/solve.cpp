// https://www.acmicpc.net/problem/1937
// 욕심쟁이 판다
// Written in C++ langs
// 2020. 06. 08.
// Wizley

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <string.h>

using namespace std;

int N;
int FOREST[500][500];
int DP[500][500];

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

int dfs(int x, int y){
    
    // 이미 최대 생존 일수가 구해진 경우
    if(DP[x][y] > 0){
        return DP[x][y];
    }
    
    // 첫 방문시 최대 생존일은 1;
    DP[x][y] = 1;
    
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx<0 || ny<0 || nx>=N || ny>=N) continue;
        
        // 최대 생존 일수를 재귀를 통해 알아내서 최신화
        if(FOREST[nx][ny] > FOREST[x][y]){
            DP[x][y] = max(DP[x][y], dfs(nx,ny)+1);
        }
    }
    
    return DP[x][y];
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> FOREST[i][j];
        }
    }
    
    int days = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            days = max(days, dfs(i,j));
        }
    }
    
    cout << days << "\n";
    
    return 0;
    
}

