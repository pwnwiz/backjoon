// https://www.acmicpc.net/problem/3184
// 양
// Written in C++ langs
// 2020. 04. 17.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
#include <tuple>

using namespace std;

int X, Y;
char MAP[250][250]={0,};
bool VISITED[250][250]={0,};

int SHEEP = 0;
int WOLVES = 0;

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

void bfs(int x, int y){
    queue<pair<int,int>> queue;
    int o = 0;
    int v = 0;
    
    queue.push(make_pair(x,y));
    if(MAP[x][y] == 'o') o++;
    else if(MAP[x][y] == 'v') v++;
    VISITED[x][y] = true;
    
    while(!queue.empty()){
        int cur_x = queue.front().first;
        int cur_y = queue.front().second;
        queue.pop();
        
        for(int i=0; i<4; i++){
            int nx = cur_x + dx[i];
            int ny = cur_y + dy[i];
            
            if(nx<0 || ny<0 || nx>=X || ny>=Y) continue;
            
            if(MAP[nx][ny]!='#' && !VISITED[nx][ny]){
                VISITED[nx][ny] = true;
                if(MAP[nx][ny] == 'o') o++;
                if(MAP[nx][ny] == 'v') v++;
                queue.push(make_pair(nx,ny));
            }
        }
    }
    
    if(o>v) SHEEP += o;
    else WOLVES += v;
}


int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> X >> Y;
    
    for(int x=0; x<X; x++){
        for(int y=0; y<Y; y++){
            cin >> MAP[x][y];
        }
    }

    for(int i=0; i<X; i++){
        for(int j=0; j<Y; j++){
            if(!VISITED[i][j] && MAP[i][j] != '#'){
                bfs(i,j);
            }
        }
    }
    
    cout << SHEEP << " " << WOLVES << "\n";
    
    return 0;
}

