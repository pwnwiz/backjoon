// https://www.acmicpc.net/problem/4991
// 로봇 청소기
// Written in C++ langs
// 2020. 10. 08.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int N, M;

char MAP[21][21];
bool VISITED[21][21][(1<<11)-1];

void print(){
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            cout << MAP[i][j];
        }
        cout << "\n";
    }
}

int getTargetIndex(vector<pair<int,int>> &target, int nx, int ny){
    for(int i=0; i<target.size(); i++){
        if(target[i].first == nx && target[i].second == ny){
            return i;
        }
    }
    return -1;
}

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
void bfs(pair<int,int> &robot, vector<pair<int,int>> &target){
    // x, y, bit-masking of target, cnt
    queue<tuple<int,int,int,int>> que;
    que.push({robot.first, robot.second, 0, 0});
    
    while(!que.empty()){
        int x = get<0>(que.front());
        int y = get<1>(que.front());
        int bit = get<2>(que.front());
        int cnt = get<3>(que.front());
        que.pop();

        if(bit == ((1<<target.size())-1)){
            cout << cnt << "\n";
            return;
        }
        
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx<0 || ny<0 || nx>=M || ny>=N) continue;
            if(VISITED[nx][ny][bit] || MAP[nx][ny] == 'x') continue;
            
            VISITED[nx][ny][bit] = true;
            
            if(MAP[nx][ny] == '*'){
                int idx = getTargetIndex(target, nx, ny);
                que.push({nx, ny, bit|(1<<idx) , cnt+1});
            } else {
                que.push({nx, ny, bit, cnt+1});
            }
        }
    
    }
    
    cout << -1 << "\n";
    
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    while(true){
        
        cin >> N >> M;
        
        if(!N && !M) break;
    
        for(int i=0; i<21; i++){
            for(int j=0; j<21; j++){
                for(int k=0; k<((1<<11)-1); k++){
                    VISITED[i][j][k] = false;
                }
            }
        }
    
        pair<int,int> robot;
        vector<pair<int,int>> target;
        
        for(int i=0; i<M; i++){
            for(int j=0; j<N; j++){
                cin >> MAP[i][j];
                if(MAP[i][j] == 'o') robot = make_pair(i,j);
                if(MAP[i][j] == '*') target.push_back(make_pair(i,j));
            }
        }
        bfs(robot, target);
    }
    return 0;
}

