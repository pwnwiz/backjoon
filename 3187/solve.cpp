// https://www.acmicpc.net/problem/3187
// 양치기 꿍
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
char MAP[250][250]={0,};
int VISITED[250][250]={0,};

int dx[] = {0,-1,0,1};
int dy[] = {-1,0,1,0};

int WOLVES = 0;
int SHEEP = 0;

void print(){
    cout << "DEBUG\n";
    for(int i=0; i<A; i++){
        for(int j=0; j<B; j++){
            cout << VISITED[i][j] << " ";
        }
        cout << "\n";
    }
}

void bfs(int a, int b){
    queue<pair<int,int>> que;
    int sheep = 0;
    int wolf = 0;
    
    que.push(make_pair(a,b));
    if(MAP[a][b] == 'k') sheep++;
    else if(MAP[a][b] == 'v') wolf++;
    
    while(!que.empty()){
        int x = que.front().first;
        int y = que.front().second;
        que.pop();
        
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx<0 || ny<0 || nx>=A || ny>=B) continue;
            
            if(!VISITED[nx][ny] && MAP[nx][ny]!='#'){
                VISITED[nx][ny] = true;
                if(MAP[nx][ny] == 'k') sheep++;
                else if(MAP[nx][ny] == 'v') wolf++;
                que.push(make_pair(nx,ny));
            }
        }
    }
    (sheep>wolf) ? SHEEP += sheep : WOLVES += wolf;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> A >> B;
    for(int i=0; i<A; i++){
        for(int j=0; j<B; j++){
            cin >> MAP[i][j];
        }
    }
    
    for(int i=0; i<A; i++){
        for(int j=0; j<B; j++){
            if(!VISITED[i][j] && MAP[i][j] != '#'){
                VISITED[i][j] = true;
                bfs(i,j);
            }
        }
    }
    
    cout << SHEEP << " " << WOLVES << "\n";
    
    return 0;
}

