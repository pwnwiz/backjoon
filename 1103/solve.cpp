// https://www.acmicpc.net/problem/1103
// 게임
// Written in C++ langs
// 2020. 08. 12.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
char MAP[50][50];
bool VISITED[50][50];
int FINISHED[50][50];

int COUNT = 0;

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

void backtracking(int x, int y, int cnt){
    VISITED[x][y] = true;
    
    for(int i=0; i<4; i++){
        int nx = x + dx[i]*(MAP[x][y]-'0');
        int ny = y + dy[i]*(MAP[x][y]-'0');

        if(nx<0 || ny<0 || nx>=N || ny>=M || MAP[nx][ny] == 'H'){
            COUNT = max(COUNT, cnt);
            continue;
        }
    
        if(FINISHED[nx][ny] >= cnt+1){
            continue;
        }
    
        else if(!VISITED[nx][ny]){
            VISITED[nx][ny] = true;
            backtracking(nx,ny,cnt+1);
            FINISHED[nx][ny] = cnt+1;
            VISITED[nx][ny] = false;
        }
        
        else {
            cout << "-1\n";
            exit(0);
        }
        
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> MAP[i][j];
        }
    }
    
    backtracking(0, 0, 1);
    
    cout << COUNT << "\n";

    return 0;
    
}

