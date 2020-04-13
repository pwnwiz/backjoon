// https://www.acmicpc.net/problem/1012
// 유기농 배추
// Written in C++ langs
// 2020. 04. 13.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

int N;
int X, Y, K;
bool MAP[50][50]={0,};
bool VISITED[50][50]={0,};

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

queue<pair<int,int>> QUE;
void bfs(){
    while(!QUE.empty()){
        int x = QUE.front().first;
        int y = QUE.front().second;
        QUE.pop();
        
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx<0 || ny<0 || nx>=X || ny>=Y) continue;
            
            if(MAP[nx][ny]==true && !VISITED[nx][ny]){
                VISITED[nx][ny] = true;
                QUE.push(make_pair(nx,ny));
            }
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    for(int n=0; n<N; n++){
        memset(VISITED, false, sizeof(VISITED));
        memset(MAP, false, sizeof(MAP));
        vector<pair<int,int>> Cabbages;
        int count = 0;
        int a,b;
        
        cin >> X >> Y >> K;
        
        for(int i=0; i<K; i++){
            cin >> a >> b;
            Cabbages.push_back(make_pair(a,b));
            MAP[a][b] = true;
        }
        
        for(int i=0; i<Cabbages.size(); i++){
            int cur_x = Cabbages[i].first;
            int cur_y = Cabbages[i].second;
            
            if(!VISITED[cur_x][cur_y]){
                QUE.push(Cabbages[i]);
                VISITED[cur_x][cur_y] = true;
                bfs();
                count++;
            }
        }
        cout << count << "\n";
    }
    return 0;
    
}

