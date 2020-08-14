// https://www.acmicpc.net/problem/10711
// 모래성
// Written in C++ langs
// 2020. 08. 14.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, M;
char MAP[1000][1000];
bool VISITED[1000][1000];

int dx[] = {0,0,-1,1,-1,-1,1,1};
int dy[] = {-1,1,0,0,-1,1,-1,1};

int checkSide(int x, int y){
    int cnt = 0;
    
    for(int i=0; i<8; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx<0 || ny<0 || nx>=N || ny>=M) continue;
        
        if(MAP[nx][ny] == '.') cnt++;
    }
    return cnt;
}

void bfs(){
    int count = 0;
    queue<pair<int,int>> que;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(MAP[i][j] != '.' && checkSide(i, j) >= MAP[i][j]-'0'){
                que.push(make_pair(i,j));
                VISITED[i][j] = true;
            }
        }
    }

    while(!que.empty()){
        queue<pair<int,int>> que2;
        queue<pair<int,int>> erase = que;
        
        while(!erase.empty()){
            int x = erase.front().first;
            int y = erase.front().second;
            erase.pop();
            MAP[x][y] = '.';
        }
        
        while(!que.empty()){
            int x = que.front().first;
            int y = que.front().second;
            que.pop();
            
            for(int i=0; i<8; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(nx<0 || ny<0 || nx>=N || ny>=M) continue;
                if(MAP[nx][ny] == '.' || VISITED[nx][ny]) continue;
                
                int cnt = checkSide(nx, ny);
                
                if(cnt>=MAP[nx][ny]-'0'){
                    que2.push(make_pair(nx,ny));
                    VISITED[nx][ny] = true;
                }
            }
        }
        
        que = que2;
        count++;
    }
    
    cout << count << "\n";
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    
    queue<pair<int,int>> q;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> MAP[i][j];
        }
    }
    
    bfs();
    
    return 0;
}

