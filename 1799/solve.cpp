// https://www.acmicpc.net/problem/1799
// 비숍
// Written in C++ langs
// 2020. 04. 08.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <queue>

using namespace std;

int N;
int CHESS[10][10]={0,};
vector<pair<int,int>> BISHOP;
vector<pair<int,int>> BLACK;
vector<pair<int,int>> WHITE;

int COUNT=0;
int WHITE_COUNT = 0;
int BLACK_COUNT = 0;

bool check(int x, int y){
    int dx[] = {-1, -1, 1, 1};
    int dy[] = {-1, 1, -1, 1};
    
    for(int i=1; i<N; i++){
        for(int j=0; j<4; j++){
            int nx = x + dx[j]*i;
            int ny = y + dy[j]*i;
            
            if(nx<0 || ny<0 || nx>=N || ny>=N){
                continue;
            }
            if(CHESS[nx][ny] == 2) return false;
        }
    }
    return true;
}

void white_backtracking(int bishop_count, int idx){
    WHITE_COUNT = max(WHITE_COUNT, bishop_count);
    
    if(WHITE.empty() || idx >= WHITE.size()){
        return;
    }
    
        int cur_x = WHITE[idx].first;
        int cur_y = WHITE[idx].second;
        
        if(CHESS[cur_x][cur_y] == 1 && check(cur_x, cur_y)){
            CHESS[cur_x][cur_y] = 2;
            white_backtracking(bishop_count+1, idx+1);
            CHESS[cur_x][cur_y] = 1;
        }
    
        white_backtracking(bishop_count, idx+1);
}

void black_backtracking(int bishop_count, int idx){
    BLACK_COUNT = max(BLACK_COUNT, bishop_count);
    
    if(BLACK.empty() || idx >= BLACK.size()){
        return;
    }
    
    int cur_x = BLACK[idx].first;
    int cur_y = BLACK[idx].second;
    
    if(CHESS[cur_x][cur_y] == 1 && check(cur_x, cur_y)){
        CHESS[cur_x][cur_y] = 2;
        black_backtracking(bishop_count+1, idx+1);
        CHESS[cur_x][cur_y] = 1;
    }
    
    black_backtracking(bishop_count, idx+1);
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> CHESS[i][j];
            if(CHESS[i][j] == 1){
                if((i+j)%2 == 0){
                    BLACK.push_back(make_pair(i,j));
                } else {
                    WHITE.push_back(make_pair(i,j));
                }
            }
        }
    }
    
    
    white_backtracking(0, 0);
    black_backtracking(0, 0);
    
    cout << WHITE_COUNT + BLACK_COUNT << "\n";
    
    return 0;
    
}

