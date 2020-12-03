// https://www.acmicpc.net/problem/16920
// 확장 게임
// Written in C++ langs
// 2020. 12. 03.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
#include <set>
#include <string.h>

using namespace std;

bool VISITED[1001][1001];
char MAP[1001][1001];
vector<queue<tuple<int,int,int>>> QUE;
vector<int> S;
vector<int> RESULT;
int N, M, P;

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
void bfs(){
    while(true){
        bool empty = true;
        for(int i=0; i<QUE.size(); i++){
            if(!QUE[i].empty()) empty = false;
        }
        if(empty) break;
        
        vector<queue<tuple<int,int,int>>> que2(P);
        
        for(int i=0; i<QUE.size(); i++){
            while(!QUE[i].empty()){
                int x = get<0>(QUE[i].front());
                int y = get<1>(QUE[i].front());
                int cnt = get<2>(QUE[i].front());
                QUE[i].pop();
                
                if(cnt == S[i]){
                    que2[i].push({x,y,0});
                    continue;
                }
            
                for(int j=0; j<4; j++){
                    int nx = x + dx[j];
                    int ny = y + dy[j];
                    
                    if(nx<0 || ny<0 || nx>=N || nx>=M) continue;
                    if(VISITED[nx][ny] || MAP[nx][ny] != '.') continue;
                        
                    VISITED[nx][ny] = true;
                    MAP[nx][ny] = '1' + i;
                    QUE[i].push({nx,ny,cnt+1});
                }
            }
        }
        QUE = que2;
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> P;
    
    QUE.resize(P);
    
    int input;
    for(int p=0; p<P; p++){
        cin >> input;
        S.push_back(input);
    }
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> MAP[i][j];
            if(MAP[i][j] >= '1' && MAP[i][j] <= '9'){
                QUE[MAP[i][j]-'1'].push({i,j,0});
            }
        }
    }

    bfs();
    
    RESULT.resize(P);
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(MAP[i][j]>='1' && MAP[i][j]<='9'){
                RESULT[MAP[i][j]-'1'] += 1;
            }
        }
    }
    
    for(auto r : RESULT){
        cout << r << " ";
    }
    cout << "\n";
    return 0;
}

