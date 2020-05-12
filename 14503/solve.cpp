// https://www.acmicpc.net/problem/14503
// 로봇 청소기
// Written in C++ langs
// 2020. 05. 12.
// Wizley

#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

pair<int,int> S;
int N, M;
bool ARR[50][50]={0,};
bool VISITED[50][50]={0,};
int TOTAL = 0;

int getDirection(int d){
    int next = -1;
    switch(d){
        case 0:
            next = 3;
            break;
        case 1:
            next = 0;
            break;
        case 2:
            next = 1;
            break;
        case 3:
            next = 2;
            break;
    }
    return next;
}

int getBack(int d){
    int back = -1;
    switch(d){
        case 0:
            back = 2;
            break;
        case 1:
            back = 3;
            break;
        case 2:
            back = 0;
            break;
        case 3:
            back = 1;
            break;
    }
    return back;
}

void clean(int direction){
    queue<tuple<int,int,int>> q;
    q.push({S.first, S.second, direction});
    VISITED[S.first][S.second] = true;
    TOTAL++;

    int dx[] = {0,1,0,-1};
    int dy[] = {-1,0,1,0};

    while(!q.empty()){
        int y = get<0>(q.front());
        int x = get<1>(q.front());
        int d = get<2>(q.front());
        q.pop();

        int cur_d = d;
        bool changed = false;
        
        for(int i=0; i<4; i++){
            cur_d = getDirection(cur_d);
            
            int nx = x + dx[cur_d];
            int ny = y + dy[cur_d];
            
            if(nx<0 || ny<0 || nx>=M || ny>=N) continue;
            
            if(ARR[ny][nx] == 0 && !VISITED[ny][nx]){
                VISITED[ny][nx] = true;
                TOTAL++;
                q.push({ny,nx,cur_d});
                changed = true;
                break;
            }
        }
        
        if(!changed){
            int back = getBack(d);
            int nx = x + dx[back];
            int ny = y + dy[back];
            
            if(nx<0 || ny<0 || nx>=M || ny>=N) continue;
            
            if(ARR[ny][nx] == 0){
                q.push({ny,nx,d});
            }
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    
    cin >> S.first >> S.second;
    
    int d;
    cin >> d;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> ARR[i][j];
        }
    }
    
    clean(d);
    
    cout << TOTAL << "\n";
    
    return 0;
    
}

