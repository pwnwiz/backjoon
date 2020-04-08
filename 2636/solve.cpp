// https://www.acmicpc.net/problem/2636
// 치즈
// Written in C++ langs
// 2020. 04. 08.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <queue>

using namespace std;

vector<pair<int,int>> CHEESE;
queue<pair<int,int>> AIR;
bool VISITED[100][100]={0,};
int MAP[100][100]={0,};
int RES[100]={0,};
int X, Y;
int COUNT=0;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void getCheese(){
    for(int i=0; i<X; i++){
        MAP[i][0] = 2;
        MAP[i][Y-1] = 2;
        AIR.push(make_pair(i,0));
        AIR.push(make_pair(i,Y-1));
        VISITED[i][0] = true;
        VISITED[i][Y-1] = true;
    }
    
    for(int i=1; i<Y-1; i++){
        MAP[0][i] = 2;
        MAP[X-1][i] = 2;
        AIR.push(make_pair(0,i));
        AIR.push(make_pair(X-1,i));
        VISITED[0][i] = true;
        VISITED[X-1][i] = true;
    }
    
    while(!AIR.empty()){
        int x = AIR.front().first;
        int y = AIR.front().second;
        AIR.pop();
        
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx<0 || ny<0 || nx>X || ny>Y){
                continue;
            }
            
            if(MAP[nx][ny] == 0 && !VISITED[nx][ny]){
                VISITED[nx][ny] = true;
                MAP[nx][ny] = 2;
                AIR.push(make_pair(nx,ny));
            }
            
        }
        
    }
}

void bfs(){
    queue<pair<int,int>> que;
    for(int i=0; i<CHEESE.size(); i++){
        int x = CHEESE[i].first;
        int y = CHEESE[i].second;
        
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx<0 || ny<0 || nx>X || ny>Y){
                continue;
            }
            
            if(MAP[nx][ny] == 2){
                VISITED[x][y] = true;
                que.push(make_pair(x,y));
                break;
            }
        }
        
    }
    
    while(!que.empty()){
        RES[COUNT++] = que.size();
        queue<pair<int,int>> que2;
        queue<pair<int,int>> hole;
        hole = que;

        while(!que.empty()){
            int cur_x = que.front().first;
            int cur_y = que.front().second;
            MAP[cur_x][cur_y] = 2;
            que.pop();
            
            for(int i=0; i<4; i++){
                int nx = cur_x + dx[i];
                int ny = cur_y + dy[i];
                
                if(nx<0 || ny<0 || nx>X || ny>Y){
                    continue;
                }
                
                if(MAP[nx][ny] == 1 && !VISITED[nx][ny]){
                    VISITED[nx][ny] = true;
                    que2.push(make_pair(nx,ny));
                }
            }
        }

        
        while(!hole.empty()){
            queue<pair<int,int>> hole2;
            while(!hole.empty()){
                
                int cur_x = hole.front().first;
                int cur_y = hole.front().second;
                hole.pop();
                
                for(int i=0; i<4; i++){
                    int nx = cur_x + dx[i];
                    int ny = cur_y + dy[i];
                    
                    if(nx<0 || ny<0 || nx>X || ny>Y){
                        continue;
                    }
                    
                    if(MAP[nx][ny] == 0 && !VISITED[nx][ny]){
                        MAP[nx][ny] = 2;
                        VISITED[nx][ny] = true;
                        hole2.push(make_pair(nx,ny));
                    }
                    
                    else if(MAP[nx][ny] == 1 && !VISITED[nx][ny]){
                        VISITED[nx][ny] = true;
                        que2.push(make_pair(nx,ny));
                    }
                }
            }
            hole = hole2;
        }
        que = que2;
    }
    
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> X >> Y;
    
    for(int i=0; i<X; i++){
        for(int j=0; j<Y; j++){
            cin >> MAP[i][j];
            if(MAP[i][j] == 1){
                CHEESE.push_back(make_pair(i,j));
            }
        }
    }

    getCheese();
    bfs();
    
    cout << COUNT << "\n";
    cout << RES[COUNT-1] << "\n";

    return 0;
    
}

