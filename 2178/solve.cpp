// https://www.acmicpc.net/problem/2178
// 미로 탐색
// Written in C++ langs
// 2020. 02. 24.
// Wizley

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <cstring>
#include <queue>

using namespace std;

int ARR[101][101]={0,};
int VISITED[101][101]={0,};
int N, M;
int RES = -1;
int COUNT = 1;
queue <pair<int,int>> QUEUE;

void BFS(){
    VISITED[1][1] = 1;
    
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};
    
    QUEUE.push(make_pair(1,1));
    
    while(true){
        queue <pair<int,int>> TEMPQUEUE;
        
        while(!QUEUE.empty()){
            
            int pop_x = QUEUE.front().first;
            int pop_y = QUEUE.front().second;
            QUEUE.pop();
            
            for(int i=0; i<4; i++){
                int nx = pop_x + dx[i];
                int ny = pop_y + dy[i];
                
                if(nx<=0 || ny<=0 || nx>N || ny>M)
                    continue;
                
                if(ARR[nx][ny]!=1 || VISITED[nx][ny])
                    continue;
                
                if(nx == N && ny == M){
                    RES = COUNT+1;
                    cout << RES << "\n";
                    return;
                }
                
                VISITED[nx][ny]++;
                ARR[nx][ny]=2;
                TEMPQUEUE.push(make_pair(nx, ny));
            }
        }
            
        QUEUE = TEMPQUEUE;
        if(QUEUE.empty()) break;
        COUNT++;
    }
    cout << RES << "\n";
}


int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    char input;
    
    cin >> N >> M;
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            cin >> input;
            ARR[i][j] = input - '0';
        }
    }
    
    BFS();
    
};


