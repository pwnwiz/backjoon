// https://www.acmicpc.net/problem/2146
// 다리 만들기
// Written in C++ langs
// 2020. 02. 25.
// Wizley

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <cstring>
#include <queue>

using namespace std;

int MAP[101][101]={0,};
int ISLAND[101][101]={0,};
int VISIT[101][101]={0,};
int FLAG=1;
int BRIDGECOUNT=9999999;
int M=0;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void DFS(int x, int y){
    VISIT[x][y] = 1;
    ISLAND[x][y] = FLAG;
    
    for(int i=0; i<4; i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        
        if(nx<=0 || ny<=0 || nx>M || ny>M)
            continue;
        
        if(!VISIT[nx][ny] && MAP[nx][ny]){
            DFS(nx, ny);
        }
    }
}

int BFS(int no){
    queue<pair<int,int>> que;
    int result = 0;
    
    for(int i=1; i<=M; i++){
        for(int j=1; j<=M; j++){
            if(ISLAND[i][j]==no){
                VISIT[i][j] = 1;
                que.push(make_pair(i,j));
            }
        }
    }
    while(!que.empty()){
        int queSize = que.size();
        for(int i=0; i<queSize; i++){
            int x = que.front().first;
            int y = que.front().second;
            que.pop();
            
            for(int i=0; i<4; i++){
                int nx = x+dx[i];
                int ny = y+dy[i];
                
                if(nx<=0 || ny<=0 || nx>M || ny>M)
                    continue;
                
                if(ISLAND[nx][ny]!=no){
                    if(ISLAND[nx][ny]!=0){
                        return result;
                    }
                    else if(ISLAND[nx][ny]==0 && !VISIT[nx][ny]){
                        VISIT[nx][ny] = 1;
                        que.push(make_pair(nx,ny));
                    }
                }
            }
        }
        result++;
    }
    return result;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> M;
    for(int i=1; i<=M; i++){
        for(int j=1; j<=M; j++){
            cin >> MAP[i][j];
        }
    }
    
    for(int i=1; i<=M; i++){
        for(int j=1; j<=M; j++){
            if(!VISIT[i][j] && MAP[i][j]){
                DFS(i,j);
                FLAG++;
            }
        }
    }
    
    for(int i=1; i<FLAG; i++){
        memset(VISIT, 0, sizeof(VISIT));
        BRIDGECOUNT = min(BRIDGECOUNT, BFS(i));
    }
    
    cout << BRIDGECOUNT << "\n";
    return 0;
    
}

