// https://www.acmicpc.net/problem/16197
// 두 동전
// Written in C++ langs
// 2020. 11. 06.
// Wizley

#include<algorithm>
#include<iostream>
#include<vector>
#include<set>

using namespace std;

int N, M;
char MAP[21][21];

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

int result = 987654321;
void backtracking(char map[21][21], int cnt){
    
    int count = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(map[i][j] == 'o') count++;
        }
    }

    if(count == 1){
        result = min(result, cnt);
        return;
    }
    
    if(cnt >= 10){
        return;
    }
    
    for(int i=0; i<4; i++){
        
        char new_map[21][21];
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                new_map[i][j] = map[i][j];
            }
        }
        
        for(int x=0; x<N; x++){
            for(int y=0; y<M; y++){
                if(map[x][y] != 'o') continue;
                
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(nx<0 || ny<0 || nx>=N || ny>=M){
                    new_map[x][y] = '.';
                    continue;
                }
                
                if(map[nx][ny] == '.'){
                    new_map[x][y] = '.';
                    new_map[nx][ny] = 'o';
                }
            }
        }
        backtracking(new_map, cnt+1);
    }
    
    
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> MAP[i][j];
        }
    }
    
    backtracking(MAP, 0);
    
    if(result == 987654321) result = -1;
    cout << result << "\n";

    return 0;
    
}

