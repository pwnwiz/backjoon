// https://www.acmicpc.net/problem/2234
// 성곽
// Written in C++ langs
// 2020. 04. 20.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
#include <tuple>

using namespace std;

int A, B;
int MAP[50][50]={0,};
bool VISITED[50][50]={0,};

int dx[] = {0,-1,0,1};
int dy[] = {-1,0,1,0};

int CNT = 0;
int MAX_CNT = 0;
int MAX_WALL_CNT = 0;

void print(){
    cout << "DEBUG\n";
    for(int i=0; i<A; i++){
        for(int j=0; j<B; j++){
            cout << VISITED[i][j] << " ";
        }
        cout << "\n";
    }
    
}

void bfs(int a, int b, bool flag){
    int count = 0;
    queue<pair<int,int>> que;
    VISITED[a][b] = true;
    que.push(make_pair(a,b));
    
    while(!que.empty()){
        int x = que.front().first;
        int y = que.front().second;
        count++;
        que.pop();
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx<0 || ny<0 || nx>=A || ny>=B) continue;
            
            if((MAP[x][y] & (1<<i))==0 && !VISITED[nx][ny]){
                VISITED[nx][ny] = true;
                que.push(make_pair(nx,ny));
            }
        }
    }
    
    if(!flag)MAX_CNT = max(MAX_CNT,count);
    else MAX_WALL_CNT = max(MAX_WALL_CNT,count);
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> B >> A;
    for(int i=0; i<A; i++){
        for(int j=0; j<B; j++){
            cin >> MAP[i][j];
        }
    }
    
    for(int i=0; i<A; i++){
        for(int j=0; j<B; j++){
            if(!VISITED[i][j]){
                bfs(i,j, false);
                CNT++;
            }
        }
    }
    
    
    
    for(int i=0; i<A; i++){
        for(int j=0; j<B; j++){
            for(int bit=0; bit<4; bit++){
                if(MAP[i][j] & (1<<bit)){
                    memset(VISITED, false, sizeof(VISITED));
                    MAP[i][j] -= (1<<bit);
                    bfs(i,j,true);
                    MAP[i][j] += (1<<bit);
                }
            }
        }
    }
    
    cout << CNT << "\n" << MAX_CNT << "\n" << MAX_WALL_CNT << "\n";

    
    return 0;
}

