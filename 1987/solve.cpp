// https://www.acmicpc.net/problem/1987
// 알파벳
// Written in C++ langs
// 2020. 03. 20.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

char BOARD[21][21]={0,};
bool VISITED[26]={0,};
int R, C;

int MAX=0;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void backtracking(int x, int y, int count){
    MAX = max(MAX, count);
    
    for(int i=0; i<4; i++){
        int cur_x = x + dx[i];
        int cur_y = y + dy[i];
        
        if(cur_x<1 || cur_y<1 || cur_x>R || cur_y>C){
            continue;
        }
        
        if(!VISITED[BOARD[cur_x][cur_y]-'A']){
            VISITED[BOARD[cur_x][cur_y]-'A'] = 1;
            backtracking(cur_x, cur_y, count+1);
            VISITED[BOARD[cur_x][cur_y]-'A'] = 0;
        }
    }
    
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> R >> C;
    
    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++){
            cin >> BOARD[i][j];
        }
    }
    
    VISITED[BOARD[1][1]-'A']=1;
    backtracking(1, 1, 1);

    cout << MAX << "\n";
    
    return 0;
    
}

