// https://www.acmicpc.net/problem/2589
// 보물섬
// Written in C++ langs
// 2020. 04. 16.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

int N, M;
char MAP[50][50]={0,};
bool VISITED[50][50]={0,};
vector<pair<int,int>> V_L;

int COUNT = 0;

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

void bfs(int x, int y){
    queue<pair<int,int>> que;
    int cnt = 0;
    
    VISITED[x][y] = true;
    que.push(make_pair(x,y));
    
    while(!que.empty()){
        cnt++;
        queue<pair<int,int>> que2;
        while(!que.empty()){
            int x = que.front().first;
            int y = que.front().second;
            que.pop();
            
            for(int i=0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(nx<0 || ny<0 || nx>=N || ny>=M) continue;
                
                if(MAP[nx][ny] == 'L' && !VISITED[nx][ny]){
                    VISITED[nx][ny] = true;
                    que2.push(make_pair(nx,ny));
                }
            }
        }
        que = que2;
    }
    
    COUNT = max(COUNT, cnt);
}


int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> MAP[i][j];
            if(MAP[i][j] == 'L'){
                V_L.push_back(make_pair(i,j));
            }
        }
    }
    
    for(int i=0; i<V_L.size(); i++){
        memset(VISITED, false, sizeof(VISITED));
        bfs(V_L[i].first, V_L[i].second);
    }
    
    cout << COUNT-1 << "\n";
    
    return 0;
    
}

