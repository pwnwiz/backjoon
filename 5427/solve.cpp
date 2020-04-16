// https://www.acmicpc.net/problem/5427
// 불
// Written in C++ langs
// 2020. 04. 16.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

int CASE;
int A, B;
char MAP[1001][1001]={0,};
bool VISITED[1001][1001]={0,};
bool VISITED2[1001][1001]={0,};

queue<pair<int,int>> FIRE;
queue<pair<int,int>> QUE;

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

void print(){
    cout << "//////////////////";
    cout << "\n";
    for(int i=0; i<B; i++){
        for(int j=0; j<A; j++){
            cout << MAP[i][j] << " ";
        }
        cout << "\n";
    }
    
}

bool is_escapable(){
    
    for(int i=0; i<B; i++){
        if(MAP[i][0]=='.' || MAP[i][0]=='@') return true;
        if(MAP[i][A-1]=='.' || MAP[i][A-1]=='@') return true;
    }
    
    for(int i=0; i<A; i++){
        if(MAP[0][i]=='.' || MAP[0][i]=='@') return true;
        if(MAP[B-1][i]=='.' || MAP[B-1][i]=='@') return true;
    }
    return false;
}

void bfs(){
    int cnt = 0;
    while(!FIRE.empty() || !QUE.empty()){
        queue<pair<int,int>> fire2;
        queue<pair<int,int>> que2;
        
        while(!FIRE.empty()){
            int x = FIRE.front().first;
            int y = FIRE.front().second;
            FIRE.pop();
            
            for(int i=0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(nx<0 || ny<0 || nx>=B || ny>=A) continue;
                
                if(MAP[nx][ny]!='#' && !VISITED2[nx][ny]){
                    VISITED2[nx][ny] = true;
                    MAP[nx][ny] = '*';
                    fire2.push(make_pair(nx,ny));
                }
            }
        }
        
        while(!QUE.empty()){
            int x = QUE.front().first;
            int y = QUE.front().second;
            QUE.pop();
            
            if(x==0 || x==B-1 || y==0 || y==A-1){
                cout << cnt+1 << "\n";
                return;
            }
            
            for(int i=0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(nx<0 || ny<0 || nx>=B || ny>=A) continue;
                
                if(MAP[nx][ny]=='.' && !VISITED[nx][ny]){
                    VISITED[nx][ny] = true;
                    que2.push(make_pair(nx,ny));
                }
            }
        }
        
        FIRE = fire2;
        QUE = que2;
        cnt++;
        
    }
    
    cout << "IMPOSSIBLE\n";
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> CASE;

    for(int i=0; i<CASE; i++){
        memset(VISITED, false, sizeof(VISITED));
        memset(VISITED2, false, sizeof(VISITED));
        
        cin >> A >> B;
        
        for(int b=0; b<B; b++){
            for(int a=0; a<A; a++){
                cin >> MAP[b][a];
                if(MAP[b][a] == '@'){
                    QUE.push(make_pair(b,a));
                    VISITED[b][a] = true;
                }
                else if(MAP[b][a] == '*'){
                    FIRE.push(make_pair(b,a));
                    VISITED[b][a]=true;
                }
            }
        }
        

        if(!is_escapable()){
            cout << "IMPOSSIBLE\n";
            continue;
        }
        
        bfs();
        
        while(!QUE.empty()){
            QUE.pop();
        }
        
        while(!FIRE.empty()){
            FIRE.pop();
        }
    }
    
    return 0;
}

