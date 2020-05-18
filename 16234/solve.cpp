// https://www.acmicpc.net/problem/16234
// 인구 이동
// Written in C++ langs
// 2020. 05. 18.
// Wizley

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <string.h>

using namespace std;

int N, L, R;
int MAP[100][100]={0,};
bool UNION[100][100]={0,};
bool VISITED[100][100]={0,};

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

void bfs(int x, int y){
    queue<pair<int,int>> que;
    vector<pair<int,int>> xy;
    int total = 0;
    
    VISITED[x][y] = true;
    total += MAP[x][y];
    que.push(make_pair(x,y));
    xy.push_back(make_pair(x,y));
    
    while(!que.empty()){
        int cur_x = que.front().first;
        int cur_y = que.front().second;
        que.pop();
        
        for(int i=0; i<4; i++){
            int nx = cur_x + dx[i];
            int ny = cur_y + dy[i];
            
            if(nx<0 || ny<0 || nx>=N || ny>=N) continue;
            
            if(UNION[nx][ny] && !VISITED[nx][ny]){
                int diff = abs(MAP[nx][ny]-MAP[cur_x][cur_y]);
                if(diff<L || diff>R) continue;
                
                VISITED[nx][ny] = true;
                total += MAP[nx][ny];
                que.push(make_pair(nx,ny));
                xy.push_back(make_pair(nx,ny));
            }
        }
    }
    
    int new_val = total / xy.size();
    for(int i=0; i<xy.size(); i++){
        MAP[xy[i].first][xy[i].second] = new_val;
    }
}

void simulation(){
    int cnt = 0;
    
    while(true){
        bool flag = false;
        
        memset(VISITED, false, sizeof(VISITED));
        memset(UNION, false, sizeof(UNION));
        
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                for(int k=0; k<4; k++){
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    
                    // OOB 예외 처리
                    if(nx<0 || ny<0 || nx>=N || ny>=N) continue;
                    
                    int diff = abs(MAP[nx][ny] - MAP[i][j]);

                    // 범위 확인
                    if(diff>=L && diff<=R){
                        UNION[nx][ny] = UNION[i][j] = true;
                        flag = true;
                    }
                }
            }
        }
        
        if(!flag){
            cout << cnt << "\n";
            break;
        }
        
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(!VISITED[i][j] && UNION[i][j]) bfs(i,j);
            }
        }
        
        cnt++;
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> L >> R;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> MAP[i][j];
        }
    }
    
    simulation();
    
    return 0;
    
}

