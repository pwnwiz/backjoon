// https://www.acmicpc.net/problem/5213
// 과외맨
// Written in C++ langs
// 2020. 11. 11.
// Wizley

#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <tuple>
#include <stack>

using namespace std;

struct TILE{
    int value;
    int num;
    int weight;
};

TILE MAP[501][501*2];
int PARENT[501*501];
int LAST_TILE = 1;
int N;

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
void bfs(){
    queue<pair<int,int>> que;
    que.push({0,0});
    que.push({0,1});
    MAP[0][0].weight = 1;
    MAP[0][1].weight = 1;
    
    while(!que.empty()){
        int x = que.front().first;
        int y = que.front().second;
        que.pop();
        
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx<0 || ny<0 || nx>=N || ny>=N*2) continue;
            if(MAP[nx][ny].weight || !MAP[nx][ny].num) continue;
            if(MAP[nx][ny].value != MAP[x][y].value) continue;
            
            MAP[nx][ny].weight = MAP[x][y].weight + 1;
            que.push({nx,ny});
            
            if(nx%2==0){
                if(ny%2==0){
                    MAP[nx][ny+1].weight = MAP[nx][ny].weight;
                    que.push({nx,ny+1});
                } else{
                    MAP[nx][ny-1].weight = MAP[nx][ny].weight;
                    que.push({nx,ny-1});
                }
            }
            else {
                if(ny%2==0){
                    MAP[nx][ny-1].weight = MAP[nx][ny].weight;
                    que.push({nx,ny-1});
                } else {
                    MAP[nx][ny+1].weight = MAP[nx][ny].weight;
                    que.push({nx,ny+1});
                }
            }
            
            PARENT[MAP[nx][ny].num] = MAP[x][y].num;
            LAST_TILE = max(LAST_TILE, MAP[nx][ny].num);
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    
    int idx = 1;
    int cnt = 0;
    for(int i=0; i<N; i++){
        if(i%2==0){
            for(int j=0; j<N*2; j++){
                cin >> MAP[i][j].value;
                MAP[i][j].num = idx;
                cnt++;
                if(cnt == 2){
                    idx++;
                    cnt =0;
                }
            }
        } else {
            for(int j=1; j<N*2-1; j++){
                cin >> MAP[i][j].value;
                MAP[i][j].num = idx;
                cnt++;
                if(cnt == 2){
                    idx++;
                    cnt =0;
                }
            }
        }
    }
    
    bfs();
    
    stack<int> st;
    st.push(LAST_TILE);
    for(int cur=PARENT[LAST_TILE]; cur!=0; cur=PARENT[cur]){
        st.push(cur);
    }
    
    cout << st.size() << "\n";
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
    
    cout << "\n";
    for(int i=0; i<N; i++){
        for(int j=0; j<N*2; j++){
            cout << MAP[i][j].weight << " ";
        }
        cout << "\n";
    }
    
    return 0;
}

