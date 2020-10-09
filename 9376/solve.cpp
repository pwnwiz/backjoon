// https://www.acmicpc.net/problem/9376
// 탈옥
// Written in C++ langs
// 2020. 10. 09.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
#include <cstring>

using namespace std;

vector<pair<int,int>> prisoner;
int DOOR[105][105][3];
char MAP[105][105];

int T;
int N, M;

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

int getResult(){
    int result = 987654321;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            
            if(MAP[i][j] == '*') continue;
            
            int sum = 0;
            for(int pr=0; pr<3; pr++){
                sum += DOOR[i][j][pr];
            }
            
            // If three prisoners open the same door
            if(MAP[i][j] == '#') sum -= 2;
            
            result = min(result, sum);
        }
    }
    return result;
}

void bfs(){
    
    for(int pr=0; pr<prisoner.size(); pr++){
        int x = prisoner[pr].first;
        int y = prisoner[pr].second;
        
        queue<pair<int,int>> que;
        que.push({x,y});
        DOOR[x][y][pr] = 0;
        
        while(!que.empty()){
            int cx = que.front().first;
            int cy = que.front().second;
            que.pop();
            
            for(int i=0; i<4; i++){
                int nx = cx + dx[i];
                int ny = cy + dy[i];
                
                if(nx<0 || ny<0 || nx>=N || ny>=M) continue;
                
                if(MAP[nx][ny] == '*') continue;
                
                if(MAP[nx][ny] == '#'){
                    if(DOOR[nx][ny][pr] == -1 || DOOR[nx][ny][pr]>DOOR[cx][cy][pr]+1){
                        DOOR[nx][ny][pr] = DOOR[cx][cy][pr]+1;
                        que.push({nx,ny});
                    }
                } else {
                    if(DOOR[nx][ny][pr] == -1 || DOOR[nx][ny][pr]>DOOR[cx][cy][pr]){
                        DOOR[nx][ny][pr] = DOOR[cx][cy][pr];
                        que.push({nx,ny});
                    }
                }
            }
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> T;
    
    for(int i=0; i<T; i++){
        cin >> N >> M;
        
        N += 2;
        M += 2;
        
        prisoner.clear();
        memset(DOOR, -1, sizeof(DOOR));
        
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(!i || !j || i==N-1 || j==M-1){
                    MAP[i][j] = '.';
                    continue;
                }
                cin >> MAP[i][j];
                
                if(MAP[i][j] == '$'){
                    prisoner.push_back(make_pair(i,j));
                }
            }
        }
        
        // outdoor -> indoor
        prisoner.push_back({0,0});
        
        bfs();
        cout << getResult() << "\n";
    }
    return 0;
}

