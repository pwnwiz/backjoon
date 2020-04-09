// https://www.acmicpc.net/problem/3055
// 탈출
// Written in C++ langs
// 2020. 04. 09.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <queue>

using namespace std;

queue<pair<int,int>> WATER;
pair<int,int> HEDGEHOG;
pair<int,int> DEST;
char MAP[50][50]={0,};
bool VISITED[50][50]={0,};
int R, C;
int COUNT = 0;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void bfs(){
    queue<pair<int,int>> HEDGEHOGS;
    VISITED[HEDGEHOG.first][HEDGEHOG.second] = true;
    HEDGEHOGS.push(HEDGEHOG);
    
    while(!WATER.empty() || !HEDGEHOGS.empty()){
        COUNT++;
        queue<pair<int,int>> TMP_WATER;
        queue<pair<int,int>> TMP_HEDGEHOGS;
        
        while(!WATER.empty()){
            int x = WATER.front().first;
            int y = WATER.front().second;
            WATER.pop();
            
            for(int i=0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(nx<0 || ny<0 || nx>=R || ny>=C) continue;
                
                if(MAP[nx][ny] == '.' && !VISITED[nx][ny]){
                    VISITED[nx][ny] = true;
                    TMP_WATER.push(make_pair(nx,ny));
                }
            }
        }
        WATER = TMP_WATER;
        
        while(!HEDGEHOGS.empty()){
            int x = HEDGEHOGS.front().first;
            int y = HEDGEHOGS.front().second;
            HEDGEHOGS.pop();
            
            for(int i=0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(nx<0 || ny<0 || nx>=R || ny>=C) continue;
                
                if(MAP[nx][ny] == 'D'){
                    cout << COUNT << "\n";
                    exit(0);
                }
                
                if(MAP[nx][ny] == '.' && !VISITED[nx][ny]){
                    VISITED[nx][ny] = true;
                    TMP_HEDGEHOGS.push(make_pair(nx,ny));
                }
            }
        }
        HEDGEHOGS = TMP_HEDGEHOGS;
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> R >> C;
    
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cin >> MAP[i][j];
            if(MAP[i][j] == '*'){
                WATER.push(make_pair(i,j));
                VISITED[i][j] = true;
            }
            else if(MAP[i][j] == 'S'){
                HEDGEHOG = make_pair(i,j);
            }
            else if(MAP[i][j] == 'D'){
                DEST = make_pair(i,j);
            }
        }
    }
    
    bfs();
    
    cout << "KAKTUS\n";
    
    return 0;
    
}

