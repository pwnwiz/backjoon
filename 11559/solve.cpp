// https://www.acmicpc.net/problem/11559
// Puyo Puyo
// Written in C++ langs
// 2020. 04. 15.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

char MAP[12][6]={0,};
bool VISITED[12][6]={0,};
int COUNT = 0;

queue<pair<int,int>> QUE;

queue<pair<int,int>> Q_R;
queue<pair<int,int>> Q_G;
queue<pair<int,int>> Q_B;
queue<pair<int,int>> Q_P;
queue<pair<int,int>> Q_Y;

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

void print(){
    cout << "PRINT\n";
    for(int i=0; i<12; i++){
        for(int j=0; j<6; j++){
            cout << MAP[i][j] << " ";
        }
        cout << "\n";
    }
}

void fillQueue(bool input){
    for(int i=0; i<12; i++){
        for(int j=0; j<6; j++){
            if(input) cin >> MAP[i][j];
            switch(MAP[i][j]){
                case 'R':
                    Q_R.push(make_pair(i,j));
                    break;
                case 'G':
                    Q_G.push(make_pair(i,j));
                    break;
                case 'B':
                    Q_B.push(make_pair(i,j));
                    break;
                case 'P':
                    Q_P.push(make_pair(i,j));
                    break;
                case 'Y':
                    Q_Y.push(make_pair(i,j));
                    break;
            }
        }
    }
}

bool bfs(){
    vector<pair<int,int>> to_clear;
    int cnt = 0;
    
    while(!QUE.empty()){
        int x = QUE.front().first;
        int y = QUE.front().second;
        char color = MAP[x][y];
        to_clear.push_back(QUE.front());
        QUE.pop();
        cnt++;
        
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx<0 || ny<0 || nx>=12 || ny>=6) continue;
            
            if(!VISITED[nx][ny] && MAP[nx][ny] == color){
                VISITED[nx][ny] = true;
                QUE.push(make_pair(nx,ny));
            }
        }
    }
    
    if(cnt >= 4){
        for(int i=0; i<to_clear.size(); i++){
            MAP[to_clear[i].first][to_clear[i].second] = '.';
        }
        return true;
    }
    return false;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    fillQueue(true);

    bool flag;
    
    do{
        flag = false;
        
        while(!Q_R.empty()){
            int x = Q_R.front().first;
            int y = Q_R.front().second;
            if(!VISITED[x][y]){
                VISITED[x][y] = true;
                QUE.push(Q_R.front());
                if(bfs()) flag = true;
            }
            Q_R.pop();
        }
        
        while(!Q_G.empty()){
            int x = Q_G.front().first;
            int y = Q_G.front().second;
            if(!VISITED[x][y]){
                VISITED[x][y] = true;
                QUE.push(Q_G.front());
                if(bfs()) flag = true;
            }
            Q_G.pop();
        }
        
        while(!Q_B.empty()){
            int x = Q_B.front().first;
            int y = Q_B.front().second;
            if(!VISITED[x][y]){
                VISITED[x][y] = true;
                QUE.push(Q_B.front());
                if(bfs()) flag = true;
            }
            Q_B.pop();
        }
        
        while(!Q_P.empty()){
            int x = Q_P.front().first;
            int y = Q_P.front().second;
            if(!VISITED[x][y]){
                VISITED[x][y] = true;
                QUE.push(Q_P.front());
                if(bfs()) flag = true;
            }
            Q_P.pop();
        }
        
        while(!Q_Y.empty()){
            int x = Q_Y.front().first;
            int y = Q_Y.front().second;
            if(!VISITED[x][y]){
                VISITED[x][y] = true;
                QUE.push(Q_Y.front());
                if(bfs()) flag = true;
            }
            Q_Y.pop();
        }
        
        for(int l=11; l>=1; l--){
            for(int i=11; i>=1; i--){
                for(int j=0; j<6; j++){
                    if(MAP[i][j]=='.'){
                        for(int k=i; k>=1; k--){
                            MAP[k][j] = MAP[k-1][j];
                            if(k-1==0) MAP[k-1][j]='.';
                        }
                    }
                }
            }
        }
        
        fillQueue(false);
        memset(VISITED, false, sizeof(VISITED));
        
        if(flag) COUNT++;
    }while(flag);
    
    
    cout << COUNT << "\n";
}

