// https://www.acmicpc.net/problem/2468
// 안전 영역
// Written in C++ langs
// 2020. 04. 13.
// Wizley

#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>

using namespace std;

int N;;
int MAP[100][100]={0,};
bool VISITED[100][100]={0,};
int COUNT = 1;

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

queue<pair<int,int>> QUE;
void bfs(int no){
    while(!QUE.empty()){
        int x = QUE.front().first;
        int y = QUE.front().second;
        QUE.pop();
        
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx<0 || ny<0 || nx>=N || ny>=N) continue;
            
            if(MAP[nx][ny]>no && !VISITED[nx][ny]){
                VISITED[nx][ny] = true;
                QUE.push(make_pair(nx,ny));
            }
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    int max_val = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> MAP[i][j];
            max_val = max(max_val, MAP[i][j]);
        }
    }
        
    for(int i=1; i<max_val; i++){
        int count = 0;
        memset(VISITED, false, sizeof(VISITED));
        for(int x=0; x<N; x++){
            for(int y=0; y<N; y++){
                if(!VISITED[x][y] && MAP[x][y]>i){
                    VISITED[x][y] = true;
                    QUE.push(make_pair(x,y));
                    bfs(i);
                    count++;
                }
            }
        }
        COUNT = max(COUNT, count);
    }
    cout << COUNT << "\n";
    return 0;
    
}

