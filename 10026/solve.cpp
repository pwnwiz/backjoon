// https://www.acmicpc.net/problem/10026
// 적록 색약
// Written in C++ langs
// 2020. 04. 14.
// Wizley

#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>

using namespace std;

int N;;
char MAP[100][100]={0,};
bool VISITED[100][100]={0,};

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

int COUNT = 0;

queue<pair<int,int>> QUE;
void bfs(){
    char color = MAP[QUE.front().first][QUE.front().second];
    
    while(!QUE.empty()){
        int x = QUE.front().first;
        int y = QUE.front().second;
        QUE.pop();
        
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx<0 || ny<0 || nx>=N || ny>=N) continue;
            
            if(MAP[nx][ny]==color && !VISITED[nx][ny]){
                VISITED[nx][ny] = true;
                QUE.push(make_pair(nx,ny));
            }
        }
    }
    COUNT++;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> MAP[i][j];
        }
    }
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(!VISITED[i][j]){
                VISITED[i][j] = true;
                QUE.push(make_pair(i,j));
                bfs();
            }
        }
    }
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(MAP[i][j]=='G') MAP[i][j] = 'R';
        }
    }
    cout << COUNT << " ";
    memset(VISITED, false, sizeof(VISITED));
    COUNT = 0;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(!VISITED[i][j]){
                VISITED[i][j] = true;
                QUE.push(make_pair(i,j));
                bfs();
            }
        }
    }
    
    cout << COUNT << "\n";
    
    return 0;
    
}

