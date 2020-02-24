// https://www.acmicpc.net/problem/7576
// 토마토
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
int w=0, h=0;

int ARR[1001][1001]={0,};
int VISIT[1001][1001]={0,};
int COUNT=0;

queue <pair<int,int>> QUEUE;

void BFS(){
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    
    while(true){
        queue <pair<int,int>> TEMPQUEUE;
        
        while(!QUEUE.empty()){
            
            int pop_x = QUEUE.front().first;
            int pop_y = QUEUE.front().second;
            QUEUE.pop();
            
            for(int c=0; c<4; c++){
                int nx = pop_x + dx[c];
                int ny = pop_y + dy[c];
                
                if(nx<=0 || ny<=0 || ny>w || nx>h)
                    continue;
                
                if(VISIT[nx][ny] || ARR[nx][ny]!=0)
                    continue;
                
                VISIT[nx][ny]++;
                ARR[nx][ny]=1;
                TEMPQUEUE.push(make_pair(nx,ny));
            }
        }
        
        QUEUE = TEMPQUEUE;
        if(QUEUE.empty()) break;
        COUNT++;
    }
    
    for(int i=1; i<=h; i++){
        for(int j=1; j<=w; j++){
            if(ARR[i][j]==0){
                COUNT=-1;
                break;
            }
        }
    }
    cout << COUNT << "\n";
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> w >> h;
    
    for(int i=1; i<=h; i++){
        for(int j=1; j<=w; j++){
            cin >> ARR[i][j];
            if(ARR[i][j]==1){
                QUEUE.push(make_pair(i,j));
                VISIT[i][j] = 1;
            }
        }
    }
    
    if(QUEUE.size() == h*w){
        cout << COUNT << "\n";
        return 0;
    }
    
    BFS();
    
    return 0;
    
}

