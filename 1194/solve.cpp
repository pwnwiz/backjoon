// https://www.acmicpc.net/problem/1194
// 달이 차오른다, 가자.
// Written in C++ langs
// 2020. 04. 10.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <queue>
#include <tuple>

using namespace std;

queue<tuple<int,int,int>> QUE;
int DIST[50][50][64]={0,};
char MAP[50][50]={0,};
bool KEYS[10]={0,};
int X, Y;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

void bfs(){
    while(!QUE.empty()){
        int x = get<0>(QUE.front());
        int y = get<1>(QUE.front());
        int bit = get<2>(QUE.front());
        QUE.pop();
        if(MAP[x][y] == '1'){
            cout << DIST[x][y][bit] << "\n";
            return;
        }
        
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nbit = bit;
            
            if(nx<0 || ny<0 || nx>=X || ny>=Y || MAP[nx][ny] == '#' || DIST[nx][ny][nbit]) continue;

            if(MAP[nx][ny]>='A' && MAP[nx][ny]<='F'){
                if(!(nbit & 1<<(MAP[nx][ny]-'A'))) continue;
            }
            
            else if(MAP[nx][ny]>='a' && MAP[nx][ny]<='f'){
                nbit |= (1<<(MAP[nx][ny]-'a'));
            }
            
            DIST[nx][ny][nbit] = DIST[x][y][bit] + 1;
            QUE.push({nx,ny,nbit});
        }
    }
    
    cout << "-1\n";
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> X >> Y;
    for(int i=0; i<X; i++){
        for(int j=0; j<Y; j++){
            cin >> MAP[i][j];
            if(MAP[i][j] == '0'){
                QUE.push({i,j,0});
            }
        }
    }
    
    bfs();
    
    return 0;
    
}

