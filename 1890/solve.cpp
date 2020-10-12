// https://www.acmicpc.net/problem/1890
// 점프
// Written in C++ langs
// 2020. 10. 12.
// Wizley

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int N;
long long RESULT = 0;
long long MAP[101][101];
long long DP[101][101];

int dx[] = {0,1};
int dy[] = {1,0};

long long dfs(long long x, long long y){
    if(x == N-1 && y == N-1){
        return 1;
    }
    
    if(DP[x][y] == -1){
        DP[x][y] = 0;
        
        for(int k=0; k<2; k++){
            long long nx = x + dx[k] * MAP[x][y];
            long long ny = y + dy[k] * MAP[x][y];
            
            if(nx<0 || ny<0 || nx>=N || ny>=N) continue;
            
            DP[x][y] += dfs(nx, ny);
        }
    }
    
    return DP[x][y];
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(DP, -1, sizeof(DP));
    
    cin >> N;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> MAP[i][j];
        }
    }
    
    cout << dfs(0,0) << "\n";
    return 0;
}

