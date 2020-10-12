// https://www.acmicpc.net/problem/11048
// 이동하기
// Written in C++ langs
// 2020. 10. 12.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
int MAZE[1001][1001];
int DP[1001][1001];

int dx[] = {-1, 0, -1};
int dy[] = {0, -1, -1};

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> MAZE[i][j];
            DP[i][j] = MAZE[i][j];
        }
    }
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            
            int maxv = 0;
            for(int k=0; k<3; k++){
                int nx = i + dx[k];
                int ny = j + dy[k];
                
                if(nx<0 || ny<0 || nx>=N || ny>=M) continue;
                
                maxv = max(maxv, DP[nx][ny]);
            }
            DP[i][j] += maxv;
        }
    }

    cout << DP[N-1][M-1] << "\n";
    
    return 0;
}

