// https://www.acmicpc.net/problem/16946
// 벽 부수고 이동하기 4
// Written in C++ langs
// 2020. 12. 07.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>

using namespace std;

char MAP[1001][1001];
int VISITED[1001][1001];
map<int,int> MAPP;
int N, M;

int IDX = 1;

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

void bfs(int xx, int yy){
    int cnt = 0;
    
    queue<pair<int,int>> que;
    que.push({xx,yy});
    VISITED[xx][yy] = IDX;
    cnt++;
    
    while(!que.empty()){
        int x = que.front().first;
        int y = que.front().second;
        que.pop();
            
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(VISITED[nx][ny] || nx<0 || ny<0 || nx>=N || ny>=M) continue;
            if(MAP[nx][ny] != '0') continue;
            
            que.push({nx,ny});
            VISITED[nx][ny] = IDX;
            cnt++;
        }
    }
    
    MAPP[IDX++] = cnt;
}

void print(){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(MAP[i][j] == '0') cout << '0';
            else {
                int cnt = 0;
                
                set<int> sett;
                for(int k=0; k<4; k++){
                    int ii = i + dx[k];
                    int jj = j + dy[k];
                    
                    if(ii<0 || jj<0 || ii>=N || jj>=M) continue;
                 
                    sett.insert(VISITED[ii][jj]);
                }
                
                for(auto t: sett){
                    cnt += MAPP[t];
                }
                cout << (cnt+1) % 10;
            }
        }
        cout << "\n";
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> MAP[i][j];
        }
    }
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(MAP[i][j] == '0' && !VISITED[i][j]) bfs(i, j);
        }
    }
    
    print();
    
    return 0;

}

