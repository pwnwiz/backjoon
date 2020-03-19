// https://www.acmicpc.net/problem/2186
// 문자판
// Written in C++ langs
// 2020. 03. 19.
// Wizley

#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int N, M, K;
string WORD;

char PAN[101][101]={0,};
int DP[101][101][80];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int RESULT = 0;

int dfs(int x, int y, int stage){
    if(DP[x][y][stage] != -1){
        return DP[x][y][stage];
    }
    
    if(stage >= WORD.length()){
        return 1;
    }
    
    DP[x][y][stage] = 0;
    
    for(int i=0; i<4; i++){
        for(int j=1; j<=K; j++){
            int nx = x + dx[i]*j;
            int ny = y + dy[i]*j;
            
            if(nx<0 || ny<0 || nx>=N || ny>=M){
                continue;
            }
            
            if(PAN[nx][ny] == WORD[stage]){
                DP[x][y][stage] = DP[x][y][stage] + dfs(nx,ny,stage+1);
            }
        }
    }
    
    return DP[x][y][stage];
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M >> K;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> PAN[i][j];
        }
    }
    
    cin >> WORD;
    memset(DP, -1, sizeof(DP));
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(PAN[i][j] == WORD[0]){
               RESULT = RESULT + dfs(i, j, 1);
            }
        }
    }
    
    cout << RESULT << "\n";
    
    return 0;
    
}

