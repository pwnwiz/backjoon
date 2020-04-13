// https://www.acmicpc.net/problem/2573
// 빙산
// Written in C++ langs
// 2020. 04. 13.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

int X, Y;
int MAP[300][300]={0,};
bool VISITED[300][300]={0,};
queue<pair<int,int>> ICE;
int COUNT=0;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

void print(){
    cout << "PRINT\n";
    for(int i=0; i<X; i++){
        for(int j=0; j<Y; j++){
            cout << MAP[i][j] << " ";
        }
        cout << "\n";
    }
    
}

bool is_divided(){
    int cnt = 1;
    queue<pair<int,int>> tmp_que;
    memset(VISITED, false, sizeof(VISITED));
    tmp_que.push(ICE.front());
    VISITED[tmp_que.front().first][tmp_que.front().second] = true;
    
    while(!tmp_que.empty()){
        int x = tmp_que.front().first;
        int y = tmp_que.front().second;
        tmp_que.pop();
        
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx<0 || ny<0 || nx>=X || ny>=Y) continue;
            
            if(MAP[nx][ny]>0 && !VISITED[nx][ny]){
                VISITED[nx][ny] = true;
                tmp_que.push(make_pair(nx, ny));
                cnt++;
            }
        }
    }
    return ICE.size() != cnt;
}

int bfs(){
    while(!ICE.empty()){
        queue<pair<int,int>> que2;
        int MAP2[300][300]={0,};
        
        while(!ICE.empty()){
            int x = ICE.front().first;
            int y = ICE.front().second;
            ICE.pop();

            int blank_count = 0;
            for(int i=0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(nx<0 || ny<0 || nx>=X || ny>=Y) continue;
                if(MAP[nx][ny]<=0) blank_count++;
            }
            
            MAP2[x][y] = MAP[x][y] - blank_count;
            if(MAP2[x][y]>0){
                que2.push(make_pair(x,y));
            }
        }
        
        memcpy(MAP, MAP2, sizeof(MAP2));
        ICE = que2;
        COUNT++;
        
        if(ICE.size() == 0) return 0;
        if(is_divided()) return COUNT;
            
    }
    return 0;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   
    cin >> X >> Y;
    for(int i=0; i<X; i++){
        for(int j=0; j<Y; j++){
            cin >> MAP[i][j];
            if(MAP[i][j]>0){
                ICE.push(make_pair(i,j));
            }
        }
    }
    
    cout << bfs() << "\n";
    
    
    return 0;
    
}

