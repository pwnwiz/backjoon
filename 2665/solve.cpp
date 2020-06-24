// https://www.acmicpc.net/problem/2665
// 미로만들기
// Written in C++ langs
// 2020. 06. 24.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

char MAP[50][50];
int CNT[50][50];
int N;

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

void print(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << CNT[i][j] << " ";
        }
        cout << "\n";
    }
}

void bfs(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            CNT[i][j] = 9999;
        }
    }
    
    queue<pair<int,int>> que;
    CNT[0][0] = 1;
    que.push(make_pair(0,0));
    
    while(!que.empty()){
        queue<pair<int,int>> que2;
        
        while(!que.empty()){
            int x = que.front().first;
            int y = que.front().second;
            que.pop();
            
            for(int i=0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(nx<0 || ny<0 || nx>=N || ny>=N) continue;
                
                int cnt = CNT[x][y];
                MAP[nx][ny] == '0' ? cnt += 1 : cnt = cnt;
                
                if(CNT[nx][ny] > cnt){
                    CNT[nx][ny] = cnt;
                    que2.push(make_pair(nx,ny));
                }
            }
        }
        que = que2;
    }
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
    
    bfs();
    
    if(N == 1){
        if(MAP[0][0] == '0') cout << "1\n";
        else cout << "0\n";
    } else {
        cout << CNT[N-1][N-1] -1 << "\n";
    }
    
    return 0;
    
}

