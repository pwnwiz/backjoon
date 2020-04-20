// https://www.acmicpc.net/problem/6087
// 레이저 통신
// Written in C++ langs
// 2020. 04. 20.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
#include <tuple>

using namespace std;

int A, B;
char MAP[100][100]={0,};
int VISITED[100][100][2]={0,};

int dx[] = {0,-1,0,1};
int dy[] = {-1,0,1,0};

vector<pair<int,int>> C;

void print(){
    cout << "DEBUG\n";
    for(int i=0; i<A; i++){
        for(int j=0; j<B; j++){
            cout << VISITED[i][j][1] << " ";
        }
        cout << "\n";
    }
    
}

void bfs(){
    queue<tuple<int,int,int,int>> que;
    VISITED[C[0].first][C[0].second][0] = true;
    que.push({C[0].first, C[0].second, -1, 0});
    
    while(!que.empty()){
        int x = get<0>(que.front());
        int y = get<1>(que.front());
        int dir = get<2>(que.front());
        int total = get<3>(que.front());
        que.pop();
        
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx<0 || ny<0 || nx>=A || ny>=B) continue;
            
            if(dir == -1){
                if(MAP[nx][ny]!='*' && !VISITED[nx][ny][0]){
                    VISITED[nx][ny][0] = true;
                    VISITED[nx][ny][1] = total;
                    que.push({nx,ny,i,total});
                }
            }
            
            else {
                if(MAP[nx][ny]!='*' && !VISITED[nx][ny][0]){
                    VISITED[nx][ny][0] = true;
                    if(dir == i){
                        VISITED[nx][ny][1] = total;
                        que.push({nx,ny,i,total});
                    }
                    else{
                        VISITED[nx][ny][1] = total+1;
                        que.push({nx,ny,i,total+1});
                    }
                }
                
                else if(MAP[nx][ny]!='*' && VISITED[nx][ny][0] && VISITED[nx][ny][1]>=total){
                    if(dir == i){
                        VISITED[nx][ny][1] = total;
                        que.push({nx,ny,i,total});
                    }
                    else{
                        if(total+1<=VISITED[nx][ny][1]){
                            VISITED[nx][ny][1] = total+1;
                            que.push({nx,ny,i,total+1});
                        }
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
    
    cin >> B >> A;
    for(int i=0; i<A; i++){
        for(int j=0; j<B; j++){
            cin >> MAP[i][j];
            if(MAP[i][j] == 'C') C.push_back(make_pair(i,j));
        }
    }
    
    bfs();
    
    cout << VISITED[C[1].first][C[1].second][1] << "\n";
    
    return 0;
}

