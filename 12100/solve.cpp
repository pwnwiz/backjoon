// https://www.acmicpc.net/problem/12100
// 2048 (Easy)
// Written in C++ langs
// 2020. 10. 07.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int BOARD[21][21];
int N;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

int MAX_V = 0;

void backtracking(int cnt, int board[21][21]){
    if(cnt == 5){
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                MAX_V = max(MAX_V, board[i][j]);
            }
        }
        return;
    }

    for(int d=0; d<4; d++){
        int board2[21][21] = {0,};
        bool combined[21][21] = {0,};
        
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                board2[i][j] = board[i][j];
            }
        }
        
        if(d == 0){
            for(int x=0; x<N; x++){
                for(int y=0; y<N; y++){
                    
                    if(!board2[x][y]) continue;
                    
                    int value = board2[x][y];
                    
                    int nx = x + dx[d];
                    int ny = y + dy[d];
                    
                    while(true){
                        if(nx<0 || ny<0 || nx>=N || ny>=N){
                            nx -= dx[d];
                            ny -= dy[d];
                            break;
                        }
                        
                        if(!board2[nx][ny]){
                            nx += dx[d];
                            ny += dy[d];
                        }
                        
                        else {
                            nx -= dx[d];
                            ny -= dy[d];
                            break;
                        }
                    }
                    
                    board2[x][y] = 0;
                    board2[nx][ny] = value;
                    
                    int nnx = nx + dx[d];
                    int nny = ny + dy[d];
                    if(nx<0 || ny<0 || nx>=N || ny>=N) continue;
                    if(nnx<0 || nny<0 || nnx>=N || nny>=N) continue;
                    
                    if(board2[nnx][nny] == board2[nx][ny] && !combined[nnx][nny]){
                        board2[nnx][nny] *= 2;
                        combined[nnx][nny] = true;
                        board2[nx][ny] = 0;
                    }
                }
            }
        } else if (d == 1){
            for(int x=N-1; x>=0; x--){
                for(int y=N-1; y>=0; y--){
                
                    if(!board2[x][y]) continue;
                    
                    int value = board2[x][y];
                    
                    int nx = x + dx[d];
                    int ny = y + dy[d];
                    
                    while(true){
                        if(nx<0 || ny<0 || nx>=N || ny>=N){
                            nx -= dx[d];
                            ny -= dy[d];
                            break;
                        }
                        
                        if(!board2[nx][ny]){
                            nx += dx[d];
                            ny += dy[d];
                        }
                        
                        else {
                            nx -= dx[d];
                            ny -= dy[d];
                            break;
                        }
                    }
                    
                    board2[x][y] = 0;
                    board2[nx][ny] = value;
                    
                    int nnx = nx + dx[d];
                    int nny = ny + dy[d];
                    if(nx<0 || ny<0 || nx>=N || ny>=N) continue;
                    if(nnx<0 || nny<0 || nnx>=N || nny>=N) continue;
                    
                    if(board2[nnx][nny] == board2[nx][ny] && !combined[nnx][nny]){
                        board2[nnx][nny] *= 2;
                        combined[nnx][nny] = true;
                        board2[nx][ny] = 0;
                    }
                }
            }
        } else if (d == 2){
            for(int y=0; y<N; y++){
                for(int x=0; x<N; x++){
                    if(!board2[x][y]) continue;
                    
                    int value = board2[x][y];
                    
                    int nx = x + dx[d];
                    int ny = y + dy[d];
                    
                    while(true){
                        if(nx<0 || ny<0 || nx>=N || ny>=N){
                            nx -= dx[d];
                            ny -= dy[d];
                            break;
                        }
                        
                        if(!board2[nx][ny]){
                            nx += dx[d];
                            ny += dy[d];
                        }
                        
                        else {
                            nx -= dx[d];
                            ny -= dy[d];
                            break;
                        }
                    }
                    
                    board2[x][y] = 0;
                    board2[nx][ny] = value;
                    
                    int nnx = nx + dx[d];
                    int nny = ny + dy[d];
                    if(nx<0 || ny<0 || nx>=N || ny>=N) continue;
                    if(nnx<0 || nny<0 || nnx>=N || nny>=N) continue;
                    
                    if(board2[nnx][nny] == board2[nx][ny] && !combined[nnx][nny]){
                        board2[nnx][nny] *= 2;
                        combined[nnx][nny] = true;
                        board2[nx][ny] = 0;
                    }
                }
            }
        } else {
            for(int y=N-1; y>=0; y--){
                for(int x=0; x<N; x++){
                    if(!board2[x][y]) continue;
                    
                    int value = board2[x][y];
                    
                    int nx = x + dx[d];
                    int ny = y + dy[d];
                    
                    while(true){
                        if(nx<0 || ny<0 || nx>=N || ny>=N){
                            nx -= dx[d];
                            ny -= dy[d];
                            break;
                        }
                        
                        if(!board2[nx][ny]){
                            nx += dx[d];
                            ny += dy[d];
                        }
                        
                        else {
                            nx -= dx[d];
                            ny -= dy[d];
                            break;
                        }
                    }
                    
                    board2[x][y] = 0;
                    board2[nx][ny] = value;
                    
                    int nnx = nx + dx[d];
                    int nny = ny + dy[d];
                    if(nx<0 || ny<0 || nx>=N || ny>=N) continue;
                    if(nnx<0 || nny<0 || nnx>=N || nny>=N) continue;
                    
                    if(board2[nnx][nny] == board2[nx][ny] && !combined[nnx][nny]){
                        board2[nnx][nny] *= 2;
                        combined[nnx][nny] = true;
                        board2[nx][ny] = 0;
                    }
                }
            }
        }

        backtracking(cnt+1, board2);
    }

}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> BOARD[i][j];
        }
    }
    
    backtracking(0, BOARD);
    
    cout << MAX_V << "\n";
    
    return 0;
}

