// https://www.acmicpc.net/problem/14391
// 종이 조각
// Written in C++ langs
// 2020. 10. 06.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

char MAP[4][4];

// 0은 가로
// 1은 세로
int MARK[4][4];
bool VISITED[4][4];

int MAX_V = 0;
int N, M;

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

void backtracking(int x, int y, int cnt){
    VISITED[x][y] = true;
    
    if(cnt == 0){
        for(int i=0; i<2; i++){
            VISITED[x][y] = true;
            MARK[x][y] = i;
            backtracking(x, y, cnt+1);
            MARK[x][y] = -1;
            VISITED[x][y] = false;
        }
        return;
    }
    
    if(cnt == N*M){
        bool checked[4][4] = {0,};
        int sum = 0;
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(checked[i][j]) continue;
                string number = "";
                // 가로
                if(MARK[i][j] == 0){
                    for(int y=j; y<M; y++){
                        if(MARK[i][y] == 1) break;
                        
                        number += MAP[i][y];
                        checked[i][y] = true;
                    }
                }
                // 세로
                else {
                    for(int x=i; x<N; x++){
                        if(MARK[x][j] == 0) break;
                        
                        number += MAP[x][j];
                        checked[x][j] = true;
                    }
                }
                sum += stoi(number);
            }
        }
        MAX_V = max(MAX_V, sum);
        return;
    }
    
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx<0 || ny<0 || nx>=N || ny>=M) continue;
        if(VISITED[nx][ny]) continue;
        
        for(int m=0; m<2; m++){
            VISITED[nx][ny] = true;
            MARK[nx][ny] = m;
            backtracking(nx, ny, cnt+1);
            MARK[nx][ny] = -1;
            VISITED[nx][ny] = false;
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    
    for(int n=0; n<N; n++){
        for(int m=0; m<M; m++){
            cin >> MAP[n][m];
            MAX_V += MAP[n][m] - '0';
        }
    }
        
    backtracking(0, 0, 0);
    
    cout << MAX_V << "\n";

    return 0;
}


