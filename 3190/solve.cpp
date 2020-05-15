// https://www.acmicpc.net/problem/3190
// 뱀
// Written in C++ langs
// 2020. 05. 15.
// Wizley

#include <algorithm>
#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

vector<pair<int,char>> COMMAND;
bool BOARD[101][101]={0,};
bool VISITED[101][101]={0,};

deque<pair<int,int>> SNAKE;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

int N, K, L;

int getDirection(char direction){
    int idx = -1;
    switch(direction){
        case 'U':
            idx = 0;
            break;
        case 'D':
            idx = 1;
            break;
        case 'L':
            idx = 2;
            break;
        case 'R':
            idx = 3;
            break;
    }
    
    return idx;
}

char getNextDirection(char direction, char next_direction){
    char next = 'X';
    switch(direction){
        case 'U':
            (next_direction == 'L') ? next = 'L' : next = 'R';
            break;
        case 'D':
            (next_direction == 'L') ? next = 'R' : next = 'L';
            break;
        case 'L':
            (next_direction == 'L') ? next = 'D' : next = 'U';
            break;
        case 'R':
            (next_direction == 'L') ? next = 'U' : next = 'D';
            break;
    }
    return next;
}

void simulation(){
    int time = 0;
    int total = 0;
    
    char direction = 'R';
    SNAKE.push_front(make_pair(1,1));
    
    VISITED[1][1] = true;
    
    int nx = 1;
    int ny = 1;
    
    int i=0;
    while(i<=COMMAND.size()){
        int cnt = COMMAND[i].first;
        char next_direction = COMMAND[i].second;
        
        int nd = getDirection(direction);
        nx += dx[nd];
        ny += dy[nd];
        
        time ++;
                
        // 벽에 부딪힌 경우
        if(nx<1 || ny<1 || nx>N || ny >N){
            cout << time << "\n";
            return;
        }
        
        // 몸에 부딪힌 경우
        pair<int,int> cur = make_pair(nx,ny);
        auto res = find(SNAKE.begin(), SNAKE.end(), cur);
        if(res != SNAKE.end()){
            cout << time << "\n";
            return;
        }
        
        // 머리 위치 조정
        SNAKE.push_front(make_pair(nx,ny));

        // 꼬리 위치 조정
        if(!BOARD[nx][ny] || (BOARD[nx][ny] && VISITED[nx][ny])){
            SNAKE.pop_back();
        }
        
        // 사과 먹은 개수 추가
        else if(BOARD[nx][ny] && !VISITED[nx][ny]){
            total++;
        }
        
        VISITED[nx][ny] = true;
        
        if(time == cnt){
            direction = getNextDirection(direction, next_direction);
            i++;
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> K;
    
    int x, y;
    for(int i=0; i<K; i++){
        cin >> x >> y;
        BOARD[x][y] = true;
    }
    
    cin >> L;
    int c;
    char d;
    for(int i=0; i<L; i++){
        cin >> c >> d;
        COMMAND.push_back(make_pair(c,d));
    }
    
    sort(COMMAND.begin(), COMMAND.end());
    
    simulation();

    return 0;
    
}

